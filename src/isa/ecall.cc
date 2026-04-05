#include "rviss/isa/ecall.h"

ECALL::ECALL() : InstructionTypeI(Opcode::ECALL, Register::zero, Register::zero, 0) {}
