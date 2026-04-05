#include "rvsim/isa/srli.h"

SRLI::SRLI(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::SRLI, rd, rs1, imm) {}
