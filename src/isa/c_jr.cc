#include "rviss/isa/c_jr.h"

C_JR::C_JR(Register rs1)
    : InstructionTypeCR(Opcode::C_JR, rs1, Register::zero) {}
