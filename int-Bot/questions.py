"""Question bank loader and manager."""

import json
import random
from pathlib import Path
from dataclasses import dataclass, field
from config import QUESTIONS_DIR, TOPICS


@dataclass
class Question:
    id: str
    title: str
    difficulty: str
    description: str
    examples: list[dict]
    hints: list[str]
    expected_time: str
    expected_space: str
    follow_ups: list[str]
    tags: list[str] = field(default_factory=list)

    @property
    def example_str(self) -> str:
        if not self.examples:
            return ""
        ex = self.examples[0]
        return f"Input: {ex.get('input', '')}, Output: {ex.get('output', '')}"


class QuestionBank:
    """Loads and serves DSA questions from JSON files."""

    def __init__(self, questions_dir: Path = QUESTIONS_DIR):
        self.questions_dir = questions_dir
        self._bank: dict[str, list[Question]] = {}
        self._load_all()

    def _load_all(self):
        for topic in TOPICS:
            filepath = self.questions_dir / f"{topic}.json"
            if filepath.exists():
                try:
                    data = json.loads(filepath.read_text())
                    self._bank[topic] = [self._parse(q) for q in data]
                except Exception as e:
                    print(f"[questions] Error loading {filepath.name}: {e}")

    def _parse(self, data: dict) -> Question:
        complexity = data.get("expected_complexity", {})
        return Question(
            id=data.get("id", ""),
            title=data.get("title", "Unknown"),
            difficulty=data.get("difficulty", "medium"),
            description=data.get("description", ""),
            examples=data.get("examples", []),
            hints=data.get("hints", []),
            expected_time=complexity.get("time", "?"),
            expected_space=complexity.get("space", "?"),
            follow_ups=data.get("follow_ups", []),
            tags=data.get("tags", []),
        )

    def get_question(self, topic: str, difficulty: str | None = None) -> Question | None:
        """Get a random question for a topic, optionally filtered by difficulty."""
        questions = self._bank.get(topic, [])
        if not questions:
            return None
        if difficulty:
            filtered = [q for q in questions if q.difficulty == difficulty]
            if filtered:
                questions = filtered
        return random.choice(questions)

    def get_topics(self) -> list[str]:
        """Return topics that have questions loaded."""
        return [t for t in TOPICS if t in self._bank and self._bank[t]]

    def count(self, topic: str | None = None) -> int:
        if topic:
            return len(self._bank.get(topic, []))
        return sum(len(qs) for qs in self._bank.values())
