#include "rviss/isa/sb.h"

SB::SB(Register rs1, Register rs2, uint16_t imm)
    : InstructionTypeS(Opcode::SB, rs1, rs2, imm) {}
