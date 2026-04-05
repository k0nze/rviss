#include "rviss/isa/srliw.h"

SRLIW::SRLIW(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::SRLIW, rd, rs1, imm) {}
