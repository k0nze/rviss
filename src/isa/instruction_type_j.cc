#include "rviss/isa/instruction_type_j.h"

InstructionTypeJ::InstructionTypeJ(Opcode opcode, Register rd, uint32_t imm)
    : Instruction(opcode), rd(rd), imm(imm & 0x001fffffU) {}

InstructionTypeJ::~InstructionTypeJ() = default;
