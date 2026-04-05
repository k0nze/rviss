#include "rviss/isa/lbu.h"

LBU::LBU(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::LBU, rd, rs1, imm) {}
