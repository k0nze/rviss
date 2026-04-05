#include "rviss/isa/srli.h"

SRLI::SRLI(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeI(Opcode::SRLI, rd, rs1, imm) {}
