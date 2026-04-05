#include "rviss/isa/amoand_w.h"

AMOAND_W::AMOAND_W(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::AMOAND_W, rd, rs1, rs2) {}
