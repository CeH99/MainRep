#include <iostream>

struct Node {
    int data;
    Node* next;
};

class CircularQueue {
public:
    CircularQueue() : tail(nullptr) {}

    void enqueue(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!tail) {
            newNode->next = newNode;
            tail = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue() {
        if (!tail) {
            std::cout << "Queue is empty!\n";
            return;
        }
        Node* head = tail->next;
        if (tail == head) {
            delete head;
            tail = nullptr;
        } else {
            tail->next = head->next;
            delete head;
        }
    }

    void display() {
        if (!tail) {
            std::cout << "Queue is empty!\n";
            return;
        }
        Node* temp = tail->next;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        std::cout << std::endl;
    }

    ~CircularQueue() {
        while (tail) {
            dequeue();
        }
    }

private:
    Node* tail;
};

int main() {
    CircularQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    std::cout << "Queue: ";
    queue.display();

    queue.dequeue();
    std::cout << "After one dequeue: ";
    queue.display();

    return 0;
}
