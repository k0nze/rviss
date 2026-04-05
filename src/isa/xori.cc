#include "rvsim/isa/xori.h"

XORI::XORI(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::XORI, rd, rs1, imm) {}
