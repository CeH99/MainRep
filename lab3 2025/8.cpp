#include <iostream>
using namespace std;

#define SIZE 10

class stack {
    char* stck; // holds the stack
    int tos; // index of top of stack
public:
    inline stack() {
        cout << "Constructing a stack\n";
        stck = new char[SIZE];
        tos = 0;
    }
    inline void push(char ch) {
        if (tos == SIZE) {
            cout << "Stack is full\n";
            return;
        }
        stck[tos++] = ch;
    }
    inline char pop() {
        if (tos == 0) {
            cout << "Stack is empty\n";
            return 0;
        }
        return stck[--tos];
    }
    inline ~stack() {
        delete[] stck;
        stck = nullptr;
    }

    void show_stack(stack s){
        for (int i = 0; i < tos; i++)
            cout << "Element number #" << i+1 << ": " << stck[i] << "\n";
    }
};

int main() {
    stack s1, s2;
    int i;
    
    s1.push('a');
    s2.push('x');
    s1.push('b');
    s2.push('y');
    s1.push('c');
    s2.push('z');
    
    cout << "Contents of s1:\n";
    s1.show_stack(s1);

    for (i = 0; i < 3; i++)
        cout << "Pop s1: " << s1.pop() << "\n";

    for (i = 0; i < 3; i++)
        cout << "Pop s2: " << s2.pop() << "\n";

    return 0;
}
