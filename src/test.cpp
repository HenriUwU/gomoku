#include <cstdint>
#include <iostream>

int main() {
    uint32_t    pattern = 0b00110;
    uint32_t    four = 0b0110;


    if (pattern == four)
        std::cout << "Same!" << std::endl;
    else
        std::cout << "Different!" << std::endl;
}