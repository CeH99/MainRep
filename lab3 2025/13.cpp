#include <iostream>
using namespace std;

#define SIZE 26

class stack {
    char* stck; // масив для зберігання стеку
    int tos; // індекс вершини стеку
public:
    stack() {
        cout << "Constructing a stack\n";
        stck = new char[SIZE];
        tos = 0;
    }
    
    void push(char ch) {
        if (tos == SIZE) {
            cout << "Stack is full\n";
            return;
        }
        stck[tos++] = ch;
    }
    
    char pop() {
        if (tos == 0) {
            cout << "Stack is empty\n";
            return 0;
        }
        return stck[--tos];
    }
    
    void show_stack() {
        for (int i = 0; i < tos; i++)
            cout << "Element number #" << i + 1 << ": " << stck[i] << "\n";
    }
    
    ~stack() {
        delete[] stck;
    }
};

stack loadstack() {
    stack s;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        s.push(ch);
    }
    return s;
}

stack loadstack(int upper) {
    stack s;
    char start = (upper == 1) ? 'A' : 'a';
    for (char ch = start; ch < start + 26; ch++) {
        s.push(ch);
    }
    return s;
}

int main() {
    stack s1 = loadstack();
    stack s2 = s1;

    cout << "Contents of s1:\n";
    s1.show_stack();

    cout << "Contents of s2:\n";
    s2.show_stack();

    stack s3 = loadstack(1);
    cout << "Contents of s3 (Upper case):\n";
    s3.show_stack();
    
    return 0;
}
