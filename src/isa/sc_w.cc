#include "rviss/isa/sc_w.h"

SC_W::SC_W(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::SC_W, rd, rs1, rs2) {}
