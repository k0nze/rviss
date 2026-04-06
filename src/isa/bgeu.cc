#include "rviss/isa/bgeu.h"

BGEU::BGEU(Register rs1, Register rs2, uint16_t imm)
    : InstructionTypeB(Opcode::BGEU, rs1, rs2, imm) {}
