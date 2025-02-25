#include <iostream>

class pr1 {
    static int printing; // Статичне поле
public:
    void set_print(int status) { printing = status; }
    friend bool inuse();
};

class pr2 {
    static int printing;
public:
    void set_print(int status) { printing = status; }
    friend bool inuse();
};

int pr1::printing = 0;
int pr2::printing = 0;

bool inuse() {
    if (pr1::printing == 1 || pr2::printing == 1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    pr1 printer1;
    pr2 printer2;

    printer1.set_print(1);
    if(inuse())
        std::cout << "Printer 1 is in use" << std::endl;
    else
        std::cout << "Printer 1 is not in use" << std::endl;

    printer1.set_print(0);
    inuse();

    if(inuse())
        std::cout << "Printer 1 is in use" << std::endl;
    else
        std::cout << "Printer 1 is not in use" << std::endl;


    return 0;
}
