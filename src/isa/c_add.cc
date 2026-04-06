#include "rviss/isa/c_add.h"

C_ADD::C_ADD(Register rd, Register rs2)
    : InstructionTypeCR(Opcode::C_ADD, rd, rs2) {}
