#include "rviss/isa/instruction_type_i.h"

InstructionTypeI::InstructionTypeI(Opcode opcode, Register rd, Register rs1, uint16_t imm)
    : Instruction(opcode), rd(rd), rs1(rs1), imm(static_cast<uint16_t>(imm & 0x0fffU)) {}

InstructionTypeI::~InstructionTypeI() = default;
