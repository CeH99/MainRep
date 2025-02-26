#include <iostream>

class who {
private:
    char id;
public:
    who(char c) : id(c) {
        std::cout << "Constructing who #" << id << std::endl;
    }
    ~who() {
        std::cout << "Destroying who #" << id << std::endl;
    }
};

who make_who(char id) {
    return who(id);
}

int main() {
    who a('A');
    who b('B');
    who c = make_who('C');
    
    return 0;
}
