#include "rviss/isa/instruction_type_cl.h"

InstructionTypeCL::InstructionTypeCL(Opcode opcode, Register rd, Register rs1, uint16_t imm)
    : Instruction(opcode), rd(rd), rs1(rs1), imm(imm) {}

InstructionTypeCL::~InstructionTypeCL() = default;
