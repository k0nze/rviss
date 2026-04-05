#include "rviss/isa/and.h"

AND::AND(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::AND, rd, rs1, rs2) {}
