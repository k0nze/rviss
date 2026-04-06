#include "rviss/isa/c_srai.h"

C_SRAI::C_SRAI(Register rs1, uint16_t imm)
    : InstructionTypeCB(Opcode::C_SRAI, rs1, imm) {}
