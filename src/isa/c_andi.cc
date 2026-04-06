#include "rviss/isa/c_andi.h"

C_ANDI::C_ANDI(Register rs1, uint16_t imm)
    : InstructionTypeCB(Opcode::C_ANDI, rs1, imm) {}
