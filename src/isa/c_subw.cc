#include "rviss/isa/c_subw.h"

C_SUBW::C_SUBW(Register rd_rs1, Register rs2)
    : InstructionTypeCA(Opcode::C_SUBW, rd_rs1, rs2) {}
