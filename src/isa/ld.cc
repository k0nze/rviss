#include "rviss/isa/ld.h"

LD::LD(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeI(Opcode::LD, rd, rs1, imm) {}
