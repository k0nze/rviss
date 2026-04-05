#include "rviss/isa/csrrsi.h"

CSRRSI::CSRRSI(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeI(Opcode::CSRRSI, rd, rs1, imm) {}
