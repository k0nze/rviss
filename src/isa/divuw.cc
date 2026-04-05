#include "rviss/isa/divuw.h"

DIVUW::DIVUW(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::DIVUW, rd, rs1, rs2) {}
