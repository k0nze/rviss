#include "rviss/isa/jalr.h"

JALR::JALR(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::JALR, rd, rs1, imm) {}
