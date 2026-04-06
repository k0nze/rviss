#include "rviss/isa/beq.h"

BEQ::BEQ(Register rs1, Register rs2, uint16_t imm)
    : InstructionTypeB(Opcode::BEQ, rs1, rs2, imm) {}
