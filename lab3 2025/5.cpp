#include <iostream>

inline int abs(int x) {
    return (x < 0) ? -x : x;
}

inline long abs(long x) {
    return (x < 0) ? -x : x;
}

inline double abs(double x) {
    return (x < 0) ? -x : x;
}

int main() {
    std::cout << "abs(-5): " << abs(-5) << std::endl;
    std::cout << "abs(-100000L): " << abs(-100000L) << std::endl;
    std::cout << "abs(-3.14): " << abs(-3.14) << std::endl;
    return 0;
}
