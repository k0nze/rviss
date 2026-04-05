#include "rviss/isa/xori.h"

XORI::XORI(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeI(Opcode::XORI, rd, rs1, imm) {}
