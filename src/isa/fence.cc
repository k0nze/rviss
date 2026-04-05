#include "rviss/isa/fence.h"

FENCE::FENCE(uint32_t imm)
    : InstructionTypeI(Opcode::FENCE, Register::zero, Register::zero, imm) {}
