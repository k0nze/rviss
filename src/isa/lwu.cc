#include "rviss/isa/lwu.h"

LWU::LWU(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::LWU, rd, rs1, imm) {}
