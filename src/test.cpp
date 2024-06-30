#include <cstdint>
#include <iostream>
#include <bitset>

uint32_t pPatterns[3]   = { 0b01110,  0b010110, 0b011010 };
uint32_t o5Patterns[3]  = { 0b10000,  0b00001,  0b10001  };
uint32_t o6Patterns[6]  = { 0b100000, 0b000001,
                            0b001000, 0b101001,
                            0b000100, 0b100101           };

uint32_t getSelection(uint32_t bitboard, int nbBits, int bitsPos) {
    bitboard >>= bitsPos;
    uint32_t mask = (1 << nbBits) - 1;
    uint32_t selection = bitboard & mask;
    return selection;
}

bool verifyPlayerPattern(uint32_t selection, int nbBits) {
    if (nbBits == 5) {
        if (pPatterns[0] == selection)
            return true;
    } else {
        for (int i = 1; i < 3; i++)
            if (pPatterns[i] == selection)
                return true;
    }
    return false;
}

bool verifyOpponentPattern(uint32_t selection, int nbBits) {
    if (nbBits == 5) {
        for (int i = 0; i < 3; i++)
            if (o5Patterns[i] == selection)
                return true;
    } else {
        for (int i = 0; i < 6; i++)
            if (o6Patterns[i] == selection)
                return true;
    }
    return false;
}

int main() {
    uint32_t pBitboard = 0b011101000;
    uint32_t oBitboard = 0b000000000;

    for (int i = 0; i < 9; i++) {
        if (i + 5 <= 9) {
            uint32_t pSelection = getSelection(pBitboard, 5, i);
            uint32_t oSelection = getSelection(oBitboard, 5, i);
            std::cout << "Checking 5 bits at position " << i << ": Player " << std::bitset<5>(pSelection) << ", Opponent " << std::bitset<5>(oSelection) << std::endl;
            if (verifyPlayerPattern(pSelection, 5) && !verifyOpponentPattern(oSelection, 5))
                std::cout << "Free-three detected!" << std::endl;
        }
        if (i + 6 <= 9) {
            uint32_t pSelection = getSelection(pBitboard, 6, i);
            uint32_t oSelection = getSelection(oBitboard, 6, i);
            std::cout << "Checking 6 bits at position " << i << ": Player " << std::bitset<6>(pSelection) << ", Opponent " << std::bitset<6>(oSelection) << std::endl;
            if (verifyPlayerPattern(pSelection, 6) && !verifyOpponentPattern(oSelection, 6))
                std::cout << "Free-three detected!" << std::endl;
        }
    }
}
