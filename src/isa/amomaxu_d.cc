#include "rviss/isa/amomaxu_d.h"

AMOMAXU_D::AMOMAXU_D(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::AMOMAXU_D, rd, rs1, rs2) {}
