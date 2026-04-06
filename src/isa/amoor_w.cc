#include "rviss/isa/amoor_w.h"

AMOOR_W::AMOOR_W(Register rd, Register rs1, Register rs2)
    : InstructionTypeAMO(Opcode::AMOOR_W, rd, rs1, rs2) {}
