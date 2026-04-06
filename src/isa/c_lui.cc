#include "rviss/isa/c_lui.h"

C_LUI::C_LUI(Register rd, uint16_t imm)
    : InstructionTypeCI(Opcode::C_LUI, rd, imm) {}
