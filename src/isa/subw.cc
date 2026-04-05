#include "rviss/isa/subw.h"

SUBW::SUBW(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::SUBW, rd, rs1, rs2) {}
