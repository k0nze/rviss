#include "rviss/isa/xor.h"

XOR::XOR(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::XOR, rd, rs1, rs2) {}
