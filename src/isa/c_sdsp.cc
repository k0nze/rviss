#include "rviss/isa/c_sdsp.h"

C_SDSP::C_SDSP(Register rs2, uint16_t imm)
    : InstructionTypeCSS(Opcode::C_SDSP, rs2, imm) {}
