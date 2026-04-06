#include "rviss/isa/sc_d.h"

SC_D::SC_D(Register rd, Register rs1, Register rs2)
    : InstructionTypeAMO(Opcode::SC_D, rd, rs1, rs2) {}
