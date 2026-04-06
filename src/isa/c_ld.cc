#include "rviss/isa/c_ld.h"

C_LD::C_LD(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeCL(Opcode::C_LD, rd, rs1, imm) {}
