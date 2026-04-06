#include "rviss/isa/amomax_w.h"

AMOMAX_W::AMOMAX_W(Register rd, Register rs1, Register rs2)
    : InstructionTypeAMO(Opcode::AMOMAX_W, rd, rs1, rs2) {}
