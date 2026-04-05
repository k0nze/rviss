#include "rviss/isa/lb.h"

LB::LB(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeI(Opcode::LB, rd, rs1, imm) {}
