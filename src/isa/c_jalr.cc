#include "rviss/isa/c_jalr.h"

C_JALR::C_JALR(Register rs1)
    : InstructionTypeCR(Opcode::C_JALR, rs1, Register::zero) {}
