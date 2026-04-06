#include "rviss/isa/c_bnez.h"

C_BNEZ::C_BNEZ(Register rs1, uint16_t imm)
    : InstructionTypeCB(Opcode::C_BNEZ, rs1, imm) {}
