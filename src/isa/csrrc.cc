#include "rviss/isa/csrrc.h"

CSRRC::CSRRC(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::CSRRC, rd, rs1, imm) {}
