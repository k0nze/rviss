#include "rviss/isa/remu.h"

REMU::REMU(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::REMU, rd, rs1, rs2) {}
