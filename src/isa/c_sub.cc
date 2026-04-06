#include "rviss/isa/c_sub.h"

C_SUB::C_SUB(Register rd_rs1, Register rs2)
    : InstructionTypeCA(Opcode::C_SUB, rd_rs1, rs2) {}
