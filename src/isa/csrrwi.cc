#include "rviss/isa/csrrwi.h"

CSRRWI::CSRRWI(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::CSRRWI, rd, rs1, imm) {}
