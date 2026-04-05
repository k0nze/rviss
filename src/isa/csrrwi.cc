#include "rviss/isa/csrrwi.h"

CSRRWI::CSRRWI(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeI(Opcode::CSRRWI, rd, rs1, imm) {}
