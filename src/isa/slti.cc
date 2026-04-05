#include "rvsim/isa/slti.h"

SLTI::SLTI(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::SLTI, rd, rs1, imm) {}
