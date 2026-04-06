#include "rviss/isa/jal.h"

JAL::JAL(Register rd, uint32_t imm)
    : InstructionTypeJ(Opcode::JAL, rd, imm) {}
