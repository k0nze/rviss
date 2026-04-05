#include "rvsim/isa/slli.h"

SLLI::SLLI(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::SLLI, rd, rs1, imm) {}
