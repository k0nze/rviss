#include "rviss/isa/c_lwsp.h"

C_LWSP::C_LWSP(Register rd, uint16_t imm)
    : InstructionTypeCI(Opcode::C_LWSP, rd, imm) {}
