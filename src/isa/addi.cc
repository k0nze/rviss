#include "rviss/isa/addi.h"

ADDI::ADDI(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeI(Opcode::ADDI, rd, rs1, imm) {}
