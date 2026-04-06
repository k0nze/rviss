#include "rviss/isa/c_beqz.h"

C_BEQZ::C_BEQZ(Register rs1, uint16_t imm)
    : InstructionTypeCB(Opcode::C_BEQZ, rs1, imm) {}
