#include "rviss/isa/instruction_type_ci.h"

InstructionTypeCI::InstructionTypeCI(Opcode opcode, Register rd_rs1, uint16_t imm)
    : Instruction(opcode), rd_rs1(rd_rs1), imm(imm) {}

InstructionTypeCI::~InstructionTypeCI() = default;
