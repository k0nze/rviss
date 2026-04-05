#include "rviss/isa/slt.h"

SLT::SLT(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::SLT, rd, rs1, rs2) {}
