#include "rvsim/isa/ori.h"

ORI::ORI(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::ORI, rd, rs1, imm) {}
