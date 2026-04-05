#include "rviss/isa/amoand_d.h"

AMOAND_D::AMOAND_D(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::AMOAND_D, rd, rs1, rs2) {}
