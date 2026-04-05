#include "rviss/isa/div.h"

DIV::DIV(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::DIV, rd, rs1, rs2) {}
