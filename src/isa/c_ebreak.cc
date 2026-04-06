#include "rviss/isa/c_ebreak.h"

C_EBREAK::C_EBREAK()
    : InstructionTypeCR(Opcode::C_EBREAK, Register::zero, Register::zero) {}
