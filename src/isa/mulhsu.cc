#include "rviss/isa/mulhsu.h"

MULHSU::MULHSU(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::MULHSU, rd, rs1, rs2) {}
