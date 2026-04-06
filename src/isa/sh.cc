#include "rviss/isa/sh.h"

SH::SH(Register rs1, Register rs2, uint16_t imm)
    : InstructionTypeS(Opcode::SH, rs1, rs2, imm) {}
