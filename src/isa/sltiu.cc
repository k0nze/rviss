#include "rviss/isa/sltiu.h"

SLTIU::SLTIU(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeI(Opcode::SLTIU, rd, rs1, imm) {}
