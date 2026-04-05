#include "rviss/isa/ebreak.h"

EBREAK::EBREAK() : InstructionTypeI(Opcode::EBREAK, Register::zero, Register::zero, 0) {}
