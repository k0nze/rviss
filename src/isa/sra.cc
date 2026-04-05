#include "rviss/isa/sra.h"

SRA::SRA(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::SRA, rd, rs1, rs2) {}
