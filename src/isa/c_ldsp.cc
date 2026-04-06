#include "rviss/isa/c_ldsp.h"

C_LDSP::C_LDSP(Register rd, uint16_t imm)
    : InstructionTypeCI(Opcode::C_LDSP, rd, imm) {}
