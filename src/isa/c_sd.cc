#include "rviss/isa/c_sd.h"

C_SD::C_SD(Register rs1, Register rs2, uint16_t imm)
    : InstructionTypeCS(Opcode::C_SD, rs1, rs2, imm) {}
