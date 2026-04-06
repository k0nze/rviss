#include "rviss/isa/amoxor_d.h"

AMOXOR_D::AMOXOR_D(Register rd, Register rs1, Register rs2)
    : InstructionTypeAMO(Opcode::AMOXOR_D, rd, rs1, rs2) {}
