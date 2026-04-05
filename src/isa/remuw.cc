#include "rviss/isa/remuw.h"

REMUW::REMUW(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::REMUW, rd, rs1, rs2) {}
