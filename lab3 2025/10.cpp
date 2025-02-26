#include <iostream>

class Example {
public:
    int value;
    Example(int v) : value(v) {}
    void show() { std::cout << "Value: " << value << std::endl; }
};

Example* createObject() {
    Example obj(42);  // local object
    return &obj;       // cannot return the address of a local object
}

int main() {
    Example* ptr = createObject();  // ptr is now a dangling pointer
    ptr->show();  // undefined behavior
    return 0;
}
