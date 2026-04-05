#include "rviss/isa/amominu_w.h"

AMOMINU_W::AMOMINU_W(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::AMOMINU_W, rd, rs1, rs2) {}
