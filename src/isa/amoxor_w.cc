#include "rviss/isa/amoxor_w.h"

AMOXOR_W::AMOXOR_W(Register rd, Register rs1, Register rs2)
    : InstructionTypeAMO(Opcode::AMOXOR_W, rd, rs1, rs2) {}
