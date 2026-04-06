#include "rviss/isa/c_or.h"

C_OR::C_OR(Register rd_rs1, Register rs2)
    : InstructionTypeCA(Opcode::C_OR, rd_rs1, rs2) {}
