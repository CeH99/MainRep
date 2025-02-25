#include <iostream>

class base {
    int a;
public:
    void load_a(int n) { a = n; }
    int get_a() { return a; }
};

class derived : public base {
    int b;
public:
    void load_b(int n) { b = n; }
    int get_b() { return b; }
};

int main() {
    derived obj1, obj2;

    obj1.load_a(10);
    obj1.load_b(20);

    std::cout << "Before assignment:" << std::endl;
    std::cout << "obj1: a = " << obj1.get_a() << ", b = " << obj1.get_b() << std::endl;
    std::cout << "obj2: a = " << obj2.get_a() << ", b = " << obj2.get_b() << std::endl;

    obj2 = obj1; 

    std::cout << "After assignment:" << std::endl;
    std::cout << "obj1: a = " << obj1.get_a() << ", b = " << obj1.get_b() << std::endl;
    std::cout << "obj2: a = " << obj2.get_a() << ", b = " << obj2.get_b() << std::endl;

    return 0;
}
//При присвоєнні obj2 = obj1 копіюються всі дані, як з базового (a), так і з похідного (b) класу
