#include "rviss/isa/c_lw.h"

C_LW::C_LW(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeCL(Opcode::C_LW, rd, rs1, imm) {}
