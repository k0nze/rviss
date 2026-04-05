#include "rviss/isa/lhu.h"

LHU::LHU(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::LHU, rd, rs1, imm) {}
