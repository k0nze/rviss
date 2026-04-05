#include "rviss/isa/fence.h"

FENCE::FENCE(uint16_t imm)
    : InstructionTypeI(Opcode::FENCE, Register::zero, Register::zero, imm) {}
