#include "rviss/isa/remw.h"

REMW::REMW(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::REMW, rd, rs1, rs2) {}
