#include "rviss/isa/sraiw.h"

SRAIW::SRAIW(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeI(Opcode::SRAIW, rd, rs1, imm) {}
