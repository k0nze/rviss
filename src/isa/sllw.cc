#include "rviss/isa/sllw.h"

SLLW::SLLW(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::SLLW, rd, rs1, rs2) {}
