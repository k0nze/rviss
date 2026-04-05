#include "rviss/isa/amominu_d.h"

AMOMINU_D::AMOMINU_D(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::AMOMINU_D, rd, rs1, rs2) {}
