#include "rviss/isa/amoswap_w.h"

AMOSWAP_W::AMOSWAP_W(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::AMOSWAP_W, rd, rs1, rs2) {}
