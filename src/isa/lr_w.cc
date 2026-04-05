#include "rviss/isa/lr_w.h"

LR_W::LR_W(Register rd, Register rs1)
    : InstructionTypeR(Opcode::LR_W, rd, rs1, Register::zero) {}
