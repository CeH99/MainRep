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
    }

    ~strtype() {
        delete[] p;
    }

    void show() const {
        std::cout << p << " - length: " << length << std::endl;
    }

    friend char* get_string(strtype &s);
};

char* get_string(strtype &s) {
    return s.p;
}

int main() {
    strtype s1("This is a test.");
    strtype s2("I like C++.");

    std::cout << "s1 - " << get_string(s1);

    return 0;
}