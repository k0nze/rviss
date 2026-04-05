#include "rviss/isa/amomin_w.h"

AMOMIN_W::AMOMIN_W(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::AMOMIN_W, rd, rs1, rs2) {}
