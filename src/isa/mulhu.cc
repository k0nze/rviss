#include "rviss/isa/mulhu.h"

MULHU::MULHU(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::MULHU, rd, rs1, rs2) {}
