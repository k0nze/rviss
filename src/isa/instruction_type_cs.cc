#include "rviss/isa/instruction_type_cs.h"

InstructionTypeCS::InstructionTypeCS(Opcode opcode, Register rs1, Register rs2, uint16_t imm)
    : Instruction(opcode), rs1(rs1), rs2(rs2), imm(imm) {}

InstructionTypeCS::~InstructionTypeCS() = default;
