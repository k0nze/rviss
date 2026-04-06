#include "rviss/isa/c_mv.h"

C_MV::C_MV(Register rd, Register rs2)
    : InstructionTypeCR(Opcode::C_MV, rd, rs2) {}
