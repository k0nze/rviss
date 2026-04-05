#include "rviss/isa/csrrci.h"

CSRRCI::CSRRCI(Register rd, Register rs1, uint32_t imm)
    : InstructionTypeI(Opcode::CSRRCI, rd, rs1, imm) {}
