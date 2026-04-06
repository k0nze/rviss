#include "rviss/isa/bge.h"

BGE::BGE(Register rs1, Register rs2, uint16_t imm)
    : InstructionTypeB(Opcode::BGE, rs1, rs2, imm) {}
