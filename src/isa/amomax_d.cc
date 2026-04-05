#include "rviss/isa/amomax_d.h"

AMOMAX_D::AMOMAX_D(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::AMOMAX_D, rd, rs1, rs2) {}
