#include "rviss/isa/c_and.h"

C_AND::C_AND(Register rd_rs1, Register rs2)
    : InstructionTypeCA(Opcode::C_AND, rd_rs1, rs2) {}
