#include "rviss/isa/csrrci.h"

CSRRCI::CSRRCI(Register rd, Register rs1, uint16_t imm)
    : InstructionTypeI(Opcode::CSRRCI, rd, rs1, imm) {}
