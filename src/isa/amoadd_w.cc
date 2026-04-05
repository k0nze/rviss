#include "rviss/isa/amoadd_w.h"

AMOADD_W::AMOADD_W(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::AMOADD_W, rd, rs1, rs2) {}
