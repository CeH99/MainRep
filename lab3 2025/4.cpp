#include <iostream>

inline int simple_inline(int x) {
    std::cout << "Simple inline function called\n";
    return x * x;
}

inline int recursive_inline(int x) {
    std::cout << "Recursive inline function called\n";
    if (x <= 1) return 1;
    return x * recursive_inline(x - 1);
}

inline int static_var_inline(int x) {
    static int counter = 0;
    counter += x;
    std::cout << "Static var inline function called, counter: " << counter << "\n";
    return counter;
}

inline int loop_inline(int x) {
    std::cout << "Loop inline function called\n";
    int sum = 0;
    for (int i = 0; i < x; i++) {
        sum += i;
    }
    return sum;
}

inline int switch_inline(int x) {
    std::cout << "Switch inline function called\n";
    switch (x) {
        case 1: return 10;
        case 2: return 20;
        default: return 30;
    }
}

int main() {
    std::cout << "Simple inline: " << simple_inline(5) << "\n";
    std::cout << "Recursive inline: " << recursive_inline(5) << "\n";
    std::cout << "Static var inline: " << static_var_inline(5) << "\n";
    std::cout << "Loop inline: " << loop_inline(5) << "\n";
    std::cout << "Switch inline: " << switch_inline(2) << "\n";
    return 0;
}
