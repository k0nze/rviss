#include "rviss/isa/sd.h"

SD::SD(Register rs1, Register rs2, uint16_t imm)
    : InstructionTypeS(Opcode::SD, rs1, rs2, imm) {}
