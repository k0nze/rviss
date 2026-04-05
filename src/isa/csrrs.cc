#include "rviss/isa/csrrs.h"

CSRRS::CSRRS(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::CSRRS, rd, rs1, imm) {}
