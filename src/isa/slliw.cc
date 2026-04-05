#include "rviss/isa/slliw.h"

SLLIW::SLLIW(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeI(Opcode::SLLIW, rd, rs1, imm) {}
