#include "rviss/isa/addiw.h"

ADDIW::ADDIW(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeI(Opcode::ADDIW, rd, rs1, imm) {}
