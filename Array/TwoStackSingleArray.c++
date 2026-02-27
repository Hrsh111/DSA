// Two stacks using single array
#include <iostream>
#define MAX_SIZE 100

class TwoStacks {
private:
    int arr[MAX_SIZE];
    int top1, top2;

public:
    TwoStacks() {
        top1 = -1;
        top2 = MAX_SIZE;
    }

    void push1(int x) {
        if (top1 + 1 == top2) {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[++top1] = x;
    }

    void push2(int x) {
        if (top1 + 1 == top2) {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[--top2] = x;
    }

    void pop1() {
        if (top1 == -1) {
            std::cout << "Stack Underflow\n";
            return;
        }
        top1--;
    }

    void pop2() {
        if (top2 == MAX_SIZE) {
            std::cout << "Stack Underflow\n";
            return;
        }
        top2++;
    }

    int peek1() {
        if (top1 == -1) {
            std::cout << "Stack 1 is empty\n";
            return -1;
        }
        return arr[top1];
    }

    int peek2() {
        if (top2 == MAX_SIZE) {
            std::cout << "Stack 2 is empty\n";
            return -1;
        }
        return arr[top2];
    }

    void display1() {
        for (int i = top1; i >= 0; i--) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }

    void display2() {
        for (int i = top2; i < MAX_SIZE; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    TwoStacks ts;
    ts.push1(10);
    ts.push1(20);
    ts.push2(30);
    ts.push2(40);
    ts.display1();
    ts.display2();
    ts.pop1();
    ts.pop2();
    ts.display1();
    ts.display2();
    return 0;
}
