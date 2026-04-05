#include "rviss/isa/add.h"

ADD::ADD(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::ADD, rd, rs1, rs2) {}
