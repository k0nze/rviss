#include "rviss/isa/mulh.h"

MULH::MULH(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::MULH, rd, rs1, rs2) {}
