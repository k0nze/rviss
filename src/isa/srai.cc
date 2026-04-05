#include "rviss/isa/srai.h"

SRAI::SRAI(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeI(Opcode::SRAI, rd, rs1, imm) {}
