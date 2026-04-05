#include "rviss/isa/andi.h"

ANDI::ANDI(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeI(Opcode::ANDI, rd, rs1, imm) {}
