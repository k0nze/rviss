#include "rviss/isa/instruction_type_ciw.h"

InstructionTypeCIW::InstructionTypeCIW(Opcode opcode, Register rd, uint16_t imm)
    : Instruction(opcode), rd(rd), imm(imm) {}

InstructionTypeCIW::~InstructionTypeCIW() = default;
