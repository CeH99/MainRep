#include <iostream>
#define SIZE 100

class Queue {
private:
    int queue[SIZE];
    int head, tail, count;

public:
    Queue() : head(0), tail(0), count(0) {}

    bool isFull() const
    {
        return count == SIZE;
    }

    bool isEmpty() const 
    {
        return count == 0;
    }

    void push(int value) {
        if (isFull()) {
            std::cout << "Queue is full! Cannot enqueue." << std::endl;
            return;
        }
        queue[tail] = value;
        tail = (tail + 1) % SIZE;
        count++;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Queue is empty! Cannot dequeue." << std::endl;
            return -1;
        }
        int value = queue[head];
        head = (head + 1) % SIZE;
        count--;
        return value;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        std::cout << "Queue elements: ";
        for (int i = 0, index = head; i < count; i++) {
            std::cout << queue[index] << " ";
            index = (index + 1) % SIZE;
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue q;

    std::cout << "Enqueuing 5 elements..." << std::endl;
    for (int i = 1; i <= 5; i++) {
        q.push(i * 10);
    }
    q.display();

    std::cout << "Dequeuing 2 elements..." << std::endl;
    q.pop();
    q.pop();
    q.display();

    std::cout << "Enqueuing more elements..." << std::endl;
    q.push(60);
    q.push(70);
    q.display();

    return 0;
}
