#include "rviss/isa/c_nop.h"

C_NOP::C_NOP()
    : InstructionTypeCI(Opcode::C_NOP, Register::zero, 0) {}
