#include "rviss/isa/mulw.h"

MULW::MULW(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::MULW, rd, rs1, rs2) {}
