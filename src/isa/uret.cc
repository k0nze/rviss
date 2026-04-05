#include "rviss/isa/uret.h"

URET::URET()
    : InstructionTypeI(Opcode::URET, Register::zero, Register::zero, 2) {}
