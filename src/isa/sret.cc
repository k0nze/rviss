#include "rviss/isa/sret.h"

SRET::SRET()
    : InstructionTypeI(Opcode::SRET, Register::zero, Register::zero, 258) {}
