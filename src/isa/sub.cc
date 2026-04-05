#include "rviss/isa/sub.h"

SUB::SUB(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::SUB, rd, rs1, rs2) {}
