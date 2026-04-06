#include "rviss/isa/blt.h"

BLT::BLT(Register rs1, Register rs2, uint16_t imm)
    : InstructionTypeB(Opcode::BLT, rs1, rs2, imm) {}
