#include "rviss/isa/srl.h"

SRL::SRL(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::SRL, rd, rs1, rs2) {}
