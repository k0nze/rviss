#include "rviss/isa/c_li.h"

C_LI::C_LI(Register rd, uint16_t imm)
    : InstructionTypeCI(Opcode::C_LI, rd, imm) {}
