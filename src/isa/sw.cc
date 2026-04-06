#include "rviss/isa/sw.h"

SW::SW(Register rs1, Register rs2, uint16_t imm)
    : InstructionTypeS(Opcode::SW, rs1, rs2, imm) {}
