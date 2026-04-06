#include "rviss/isa/instruction_type_cb.h"

InstructionTypeCB::InstructionTypeCB(Opcode opcode, Register rs1, uint16_t imm)
    : Instruction(opcode), rs1(rs1), imm(imm) {}

InstructionTypeCB::~InstructionTypeCB() = default;
