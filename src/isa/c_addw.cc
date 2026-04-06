#include "rviss/isa/c_addw.h"

C_ADDW::C_ADDW(Register rd_rs1, Register rs2)
    : InstructionTypeCA(Opcode::C_ADDW, rd_rs1, rs2) {}
