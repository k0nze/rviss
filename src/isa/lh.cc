#include "rviss/isa/lh.h"

LH::LH(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::LH, rd, rs1, imm) {}
