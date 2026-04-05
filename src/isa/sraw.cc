#include "rviss/isa/sraw.h"

SRAW::SRAW(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::SRAW, rd, rs1, rs2) {}
