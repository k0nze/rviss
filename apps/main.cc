#include <iostream>

#include "rvsim/rvsim.h"

int main() {
    ADDI instruction(Register::a0, Register::a1, 123);

    std::cout << static_cast<int>(instruction.opcode) << std::endl;
    return 0;
}
