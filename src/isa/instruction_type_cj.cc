#include "rviss/isa/instruction_type_cj.h"

InstructionTypeCJ::InstructionTypeCJ(Opcode opcode, uint16_t imm)
    : Instruction(opcode), imm(imm) {}

InstructionTypeCJ::~InstructionTypeCJ() = default;
