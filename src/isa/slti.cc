#include "rviss/isa/slti.h"

SLTI::SLTI(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeI(Opcode::SLTI, rd, rs1, imm) {}
