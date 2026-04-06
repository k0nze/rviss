#include "rviss/isa/bltu.h"

BLTU::BLTU(Register rs1, Register rs2, uint16_t imm)
    : InstructionTypeB(Opcode::BLTU, rs1, rs2, imm) {}
