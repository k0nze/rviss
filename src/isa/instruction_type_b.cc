#include "rviss/isa/instruction_type_b.h"

InstructionTypeB::InstructionTypeB(Opcode opcode, Register rs1, Register rs2, uint16_t imm)
    : Instruction(opcode), rs1(rs1), rs2(rs2), imm(static_cast<uint16_t>(imm & 0x1fffU)) {}

InstructionTypeB::~InstructionTypeB() = default;
