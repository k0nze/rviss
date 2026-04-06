#include "rviss/isa/amomaxu_w.h"

AMOMAXU_W::AMOMAXU_W(Register rd, Register rs1, Register rs2)
    : InstructionTypeAMO(Opcode::AMOMAXU_W, rd, rs1, rs2) {}
