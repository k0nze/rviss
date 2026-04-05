#include "rvsim/isa/lui.h"

LUI::LUI(Register rd, uint32_t imm)
    : Instruction(Opcode::LUI), rd(rd), imm(imm) {}
