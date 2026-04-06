#include "rviss/isa/amoor_d.h"

AMOOR_D::AMOOR_D(Register rd, Register rs1, Register rs2)
    : InstructionTypeAMO(Opcode::AMOOR_D, rd, rs1, rs2) {}
