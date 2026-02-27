#include <iostream>
#define MAX_SIZE 100 // Maximum size of the queue

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == MAX_SIZE - 1) {
            std::cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0; // First element
        arr[++rear] = x;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            std::cout << "Queue Underflow\n";
            return;
        }
        front++;
    }

    int peek() {
        if (front == -1 || front > rear) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() { return front == -1 || front > rear; }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    std::cout << "Front element: " << q.peek() << "\n";
    return 0;
}
