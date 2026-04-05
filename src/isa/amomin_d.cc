#include "rviss/isa/amomin_d.h"

AMOMIN_D::AMOMIN_D(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::AMOMIN_D, rd, rs1, rs2) {}
