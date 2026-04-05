#include "rviss/isa/lb.h"

LB::LB(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::LB, rd, rs1, imm) {}
