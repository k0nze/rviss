#include "rviss/isa/c_slli.h"

C_SLLI::C_SLLI(Register rd_rs1, uint16_t imm)
    : InstructionTypeCI(Opcode::C_SLLI, rd_rs1, imm) {}
