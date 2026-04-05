#include "rvsim/isa/addi.h"

ADDI::ADDI(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::ADDI, rd, rs1, imm) {}
