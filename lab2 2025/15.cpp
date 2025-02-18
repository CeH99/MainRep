#include <iostream>
#include <cstring>

class strtype {
private:
    char *p;
    int length;
public:
    strtype(const char *str) {
        length = strlen(str);
        p = new char[length + 1];
        strcpy(p, str);
        std::cout << "Constructor called for: " << p << std::endl;
    }

    ~strtype() {
        std::cout << "Freeing p" << std::endl;
        delete[] p;
    }

    void show() const {
        std::cout << p << " - length: " << length << std::endl;
    }
};

int main() {
    strtype s1("This is a test.");
    strtype s2("I like C++.");

    s1.show();
    s2.show();

    return 0;
}
