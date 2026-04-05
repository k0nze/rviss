#include "rviss/isa/divu.h"

DIVU::DIVU(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::DIVU, rd, rs1, rs2) {}
