#include "rviss/isa/lui.h"

LUI::LUI(Register rd, uint32_t imm)
    : InstructionTypeU(Opcode::LUI, rd, imm) {}
