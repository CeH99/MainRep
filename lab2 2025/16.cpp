#include <iostream>
using namespace std;

#define SIZE 10

class stack {
    char* stck; // holds the stack
    int tos; // index of top of stack
public:
    stack(unsigned int size); 
    void push(char ch);
    char pop();
    ~stack();
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
    
    for (i = 0; i < 3; i++)
        cout << "Pop s1: " << s1.pop() << "\n";

    for (i = 0; i < 3; i++)
        cout << "Pop s2: " << s2.pop() << "\n";

    return 0;
}

stack::stack(unsigned int size) {
    cout << "Constructing a stack\n";
    stck = new char[size];
    tos = 0;
}

void stack::push(char ch) {
    if (tos == SIZE) {
        cout << "Stack is full\n";
        return;
    }
    stck[tos++] = ch;
}

char stack::pop() {
    if (tos == 0) {
        cout << "Stack is empty\n";
        return 0;
    }
    return stck[--tos];
}

stack::~stack()
{
    delete[] stck;
    stck = nullptr;
}