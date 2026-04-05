#include "rviss/isa/amoadd_d.h"

AMOADD_D::AMOADD_D(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::AMOADD_D, rd, rs1, rs2) {}
