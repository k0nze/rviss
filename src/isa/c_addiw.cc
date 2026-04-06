#include "rviss/isa/c_addiw.h"

C_ADDIW::C_ADDIW(Register rd_rs1, uint16_t imm)
    : InstructionTypeCI(Opcode::C_ADDIW, rd_rs1, imm) {}
