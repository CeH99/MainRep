#include <iostream>
#include <cstdint>

union ByteSwapper {
    int64_t num;
    uint8_t bytes[8]; 
};

int main() {
    ByteSwapper data;
    std::cout << "Enter 64-bit number: ";
    std::cin >> data.num;
    std::swap(data.bytes[0], data.bytes[7]);
    std::swap(data.bytes[1], data.bytes[6]);
    std::swap(data.bytes[2], data.bytes[5]);
    std::swap(data.bytes[3], data.bytes[4]);

    std::cout << "Number after swapping bytes: " << data.num << std::endl;
    return 0;
}
