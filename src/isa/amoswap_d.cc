#include "rviss/isa/amoswap_d.h"

AMOSWAP_D::AMOSWAP_D(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::AMOSWAP_D, rd, rs1, rs2) {}
