#include "rviss/isa/lw.h"

LW::LW(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::LW, rd, rs1, imm) {}
