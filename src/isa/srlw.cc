#include "rviss/isa/srlw.h"

SRLW::SRLW(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::SRLW, rd, rs1, rs2) {}
