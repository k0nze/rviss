#include "rviss/isa/divw.h"

DIVW::DIVW(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::DIVW, rd, rs1, rs2) {}
