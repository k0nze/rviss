#include "rviss/isa/mul.h"

MUL::MUL(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::MUL, rd, rs1, rs2) {}
