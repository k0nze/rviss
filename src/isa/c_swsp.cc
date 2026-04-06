#include "rviss/isa/c_swsp.h"

C_SWSP::C_SWSP(Register rs2, uint16_t imm)
    : InstructionTypeCSS(Opcode::C_SWSP, rs2, imm) {}
