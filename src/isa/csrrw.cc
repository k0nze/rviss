#include "rviss/isa/csrrw.h"

CSRRW::CSRRW(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::CSRRW, rd, rs1, imm) {}
