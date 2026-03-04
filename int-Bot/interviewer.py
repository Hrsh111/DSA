"""Core interview engine — state machine and logic."""

import time
from enum import Enum, auto
from llm import LLMClient
from voice import VoicePipeline
from watcher import FileWatcher
from questions import QuestionBank, Question
from config import MAX_HINTS, IDLE_HINT_TIMEOUT, TOPICS
import prompts
import ui


class State(Enum):
    GREETING = auto()
    TOPIC_SELECT = auto()
    ASK_QUESTION = auto()
    CODING = auto()
    EVALUATE = auto()
    FINISHED = auto()


class Interviewer:
    def __init__(self, llm: LLMClient, voice: VoicePipeline, watcher: FileWatcher | None, bank: QuestionBank):
        self.llm = llm
        self.voice = voice
        self.watcher = watcher
        self.bank = bank

        self.state = State.GREETING
        self.topic: str = ""
        self.difficulty: str = "medium"
        self.current_question: Question | None = None
        self.hints_used: int = 0
        self.last_code_change: float = 0
        self.last_code: str = ""
        self._code_change_pending = False

        # Set up LLM with interviewer persona
        self.llm.set_system_prompt(prompts.SYSTEM_PROMPT)

    def on_code_change(self, filepath: str, content: str):
        """Callback from file watcher when code changes."""
        self.last_code = content
        self.last_code_change = time.time()
        self._code_change_pending = True
        ui.print_file_change(filepath)

    def _say(self, text: str):
        """Display text and speak it."""
        ui.print_bot(text)
        self.voice.speak(text)

    def _ask_llm(self, prompt: str) -> str:
        """Send prompt to LLM, display + speak in real-time as chunks arrive."""
        stream = self.llm.chat_stream(prompt)

        # Tee the stream: print to terminal AND speak simultaneously
        def display_and_yield():
            from rich.console import Console
            console = Console()
            console.print("\n [bold blue]Algo:[/bold blue] ", end="")
            for chunk in stream:
                console.print(chunk, end="", highlight=False)
                yield chunk
            console.print()

        full_text = self.voice.speak_streamed(display_and_yield())
        return full_text

    def _get_user_input(self) -> str:
        """Get input from user via voice or text."""
        if self.voice.stt_available:
            ui.print_info("Press Enter to speak, or type your response:")
            text = ui.get_input()
            if text == "":
                # Empty input means user wants to speak
                text = self.voice.listen()
                if text:
                    ui.print_user(text)
                else:
                    ui.print_info("Didn't catch that. Please type instead.")
                    text = ui.get_input()
            return text
        else:
            return ui.get_input()

    def run(self):
        """Main interview loop."""
        ui.print_banner()

        while self.state != State.FINISHED:
            if self.state == State.GREETING:
                self._handle_greeting()
            elif self.state == State.TOPIC_SELECT:
                self._handle_topic_select()
            elif self.state == State.ASK_QUESTION:
                self._handle_ask_question()
            elif self.state == State.CODING:
                self._handle_coding()
            elif self.state == State.EVALUATE:
                self._handle_evaluate()

    def _handle_greeting(self):
        response = self._ask_llm(prompts.GREETING_PROMPT)
        self.state = State.TOPIC_SELECT

    def _handle_topic_select(self):
        available = self.bank.get_topics()
        if not available:
            available = TOPICS
        ui.print_topic_menu(available)

        user_input = self._get_user_input()
        if self._check_quit(user_input):
            return

        # Parse topic from input
        topic = self._parse_topic(user_input, available)
        if not topic:
            self._say("I didn't catch that topic. Let me show you the options again.")
            return

        # Parse difficulty if mentioned
        for diff in ["easy", "medium", "hard"]:
            if diff in user_input.lower():
                self.difficulty = diff
                break

        self.topic = topic
        self.state = State.ASK_QUESTION

    def _handle_ask_question(self):
        question = self.bank.get_question(self.topic, self.difficulty)
        if not question:
            # If no questions in bank, ask LLM to generate one
            prompt = f"Generate a {self.difficulty} {self.topic.replace('_', ' ')} interview question. State the problem clearly with one example."
            self._ask_llm(prompt)
            self.state = State.CODING
            self.current_question = None
            self.hints_used = 0
            return

        self.current_question = question
        self.hints_used = 0

        # Display question on screen
        ui.print_question(
            question.title,
            question.description,
            question.difficulty,
            question.examples,
        )

        # Have LLM present it conversationally
        prompt = prompts.QUESTION_PROMPT_TEMPLATE.format(
            title=question.title,
            description=question.description,
            example=question.example_str,
        )
        self._ask_llm(prompt)

        ui.print_status(self.topic, self.difficulty, self.hints_used, MAX_HINTS, self.voice.enabled)

        self.last_code_change = time.time()
        self.last_code = ""
        self._code_change_pending = False
        self.state = State.CODING

    def _handle_coding(self):
        """Interactive coding phase — user codes, bot observes."""
        if self.watcher:
            ui.print_info("Start coding! I'm watching your file for changes.")

        user_input = self._get_user_input()
        if self._check_quit(user_input):
            return

        lower = user_input.lower().strip()

        # Handle commands
        if lower == "hint":
            self._give_hint()
            return
        elif lower == "done":
            self.state = State.EVALUATE
            return
        elif lower == "skip":
            self._say("No problem, let's move on to the next question.")
            self.state = State.ASK_QUESTION
            return
        elif lower == "topic":
            self.state = State.TOPIC_SELECT
            return
        elif lower.startswith("voice"):
            self._toggle_voice(lower)
            return

        # If code changed recently, send it to LLM for observation
        if self._code_change_pending and self.current_question:
            self._code_change_pending = False
            observe_prompt = prompts.CODE_OBSERVATION_TEMPLATE.format(
                title=self.current_question.title,
                code=self.last_code[-3000:],  # Last 3000 chars to stay in context
                hints_given=self.hints_used,
                max_hints=MAX_HINTS,
            )
            response = self.llm.chat(observe_prompt, stream=False)
            if response.strip() and response.strip() != "...":
                self._say(response)

        # Normal conversation during coding
        if user_input:
            context = ""
            if self.last_code:
                context = f"\n[Current code state:\n{self.last_code[-2000:]}\n]\n"
            self._ask_llm(context + user_input)

    def _give_hint(self):
        if not self.current_question:
            self._say("Let me give you a general hint based on what I see.")
            self._ask_llm("The candidate asked for a hint. Give them a helpful nudge based on the conversation so far.")
            return

        if self.hints_used >= MAX_HINTS:
            self._say("I've given you all my hints for this problem. Try working with what you have, or say 'skip' to move on.")
            return

        self.hints_used += 1
        hint_text = ""
        if self.hints_used <= len(self.current_question.hints):
            hint_text = self.current_question.hints[self.hints_used - 1]

        prompt = prompts.HINT_TEMPLATE.format(
            title=self.current_question.title,
            code=self.last_code[-2000:] if self.last_code else "(no code yet)",
            hint_number=self.hints_used,
            max_hints=MAX_HINTS,
            hint_text=hint_text,
        )

        response = self._ask_llm(prompt)
        ui.print_status(self.topic, self.difficulty, self.hints_used, MAX_HINTS, self.voice.enabled)

    def _handle_evaluate(self):
        if not self.last_code and self.watcher:
            self.last_code = self.watcher.current_code

        if self.current_question:
            prompt = prompts.EVALUATE_TEMPLATE.format(
                title=self.current_question.title,
                expected_time=self.current_question.expected_time,
                expected_space=self.current_question.expected_space,
                code=self.last_code[-3000:] if self.last_code else "(no code submitted)",
            )
        else:
            prompt = f"The candidate says they're done. Their code:\n```\n{self.last_code[-3000:]}\n```\nEvaluate their solution — correctness, time/space complexity, edge cases."

        response = self._ask_llm(prompt)
        ui.print_evaluation(response)

        # Ask about follow-ups or next question
        self._say("Would you like to try another question, change topics, or quit?")
        user_input = self._get_user_input()
        if self._check_quit(user_input):
            return

        lower = user_input.lower()
        if "topic" in lower or "change" in lower:
            self.state = State.TOPIC_SELECT
        elif "quit" in lower or "exit" in lower:
            self.state = State.FINISHED
        else:
            self.state = State.ASK_QUESTION

    def _parse_topic(self, text: str, available: list[str]) -> str | None:
        text_lower = text.lower().strip()

        # Try number selection
        try:
            idx = int(text_lower) - 1
            if 0 <= idx < len(available):
                return available[idx]
        except ValueError:
            pass

        # Try matching topic name
        for topic in available:
            display = topic.replace("_", " ")
            if topic in text_lower or display in text_lower:
                return topic

        # Fuzzy match common names
        aliases = {
            "array": "arrays", "string": "strings", "tree": "trees",
            "graph": "graphs", "dynamic programming": "dp",
            "binary search": "binary_search", "stack": "stacks_queues",
            "queue": "stacks_queues", "heap": "heaps", "linked list": "linked_list",
            "backtrack": "backtracking", "system design": "system_design",
        }
        for alias, topic in aliases.items():
            if alias in text_lower and topic in available:
                return topic

        return None

    def _toggle_voice(self, command: str):
        if "off" in command:
            self.voice.enabled = False
            ui.print_info("Voice disabled. Text mode only.")
        elif "on" in command:
            self.voice.enabled = True
            ui.print_info("Voice enabled.")
        ui.print_status(self.topic or "none", self.difficulty, self.hints_used, MAX_HINTS, self.voice.enabled)

    def _check_quit(self, text: str) -> bool:
        if text.lower().strip() in ("quit", "exit", "q"):
            self._say("Great practice session! Keep grinding those DSA problems. Good luck!")
            self.state = State.FINISHED
            return True
        return False
