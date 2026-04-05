#include "rviss/isa/or.h"

OR::OR(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::OR, rd, rs1, rs2) {}
