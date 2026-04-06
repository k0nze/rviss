#include "rviss/isa/bne.h"

BNE::BNE(Register rs1, Register rs2, uint16_t imm)
    : InstructionTypeB(Opcode::BNE, rs1, rs2, imm) {}
