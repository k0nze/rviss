#include "rvsim/isa/sltiu.h"

SLTIU::SLTIU(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::SLTIU, rd, rs1, imm) {}
