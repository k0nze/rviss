#include "rviss/isa/sll.h"

SLL::SLL(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::SLL, rd, rs1, rs2) {}
