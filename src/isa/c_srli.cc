#include "rviss/isa/c_srli.h"

C_SRLI::C_SRLI(Register rs1, uint16_t imm)
    : InstructionTypeCB(Opcode::C_SRLI, rs1, imm) {}
