#include "rviss/isa/instruction_type_u.h"

InstructionTypeU::InstructionTypeU(Opcode opcode, Register rd, uint32_t imm)
    : Instruction(opcode), rd(rd), imm(imm) {}

InstructionTypeU::~InstructionTypeU() = default;
