#include "rviss/isa/lhu.h"

LHU::LHU(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeI(Opcode::LHU, rd, rs1, imm) {}
