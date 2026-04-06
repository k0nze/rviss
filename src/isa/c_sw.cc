#include "rviss/isa/c_sw.h"

C_SW::C_SW(Register rs1, Register rs2, uint16_t imm)
    : InstructionTypeCS(Opcode::C_SW, rs1, rs2, imm) {}
