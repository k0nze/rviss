#include "rviss/isa/fence_i.h"

FENCE_I::FENCE_I()
    : InstructionTypeI(Opcode::FENCE_I, Register::zero, Register::zero, 0) {}
