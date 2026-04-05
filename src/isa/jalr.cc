#include "rviss/isa/jalr.h"

JALR::JALR(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeI(Opcode::JALR, rd, rs1, imm) {}
