#include "rviss/isa/addw.h"

ADDW::ADDW(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::ADDW, rd, rs1, rs2) {}
