#include "rviss/isa/sltu.h"

SLTU::SLTU(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::SLTU, rd, rs1, rs2) {}
