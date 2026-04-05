#include "rviss/isa/lr_d.h"

LR_D::LR_D(Register rd, Register rs1)
    : InstructionTypeR(Opcode::LR_D, rd, rs1, Register::zero) {}
