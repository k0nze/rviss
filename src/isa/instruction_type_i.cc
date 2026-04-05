#include "rvsim/isa/instruction_type_i.h"

InstructionTypeI::InstructionTypeI(Opcode opcode, Register rd, Register rs1, uint32_t imm)
    : Instruction(opcode), rd(rd), rs1(rs1), imm(imm) {}

InstructionTypeI::~InstructionTypeI() = default;
