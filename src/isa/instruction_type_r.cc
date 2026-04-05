#include "rviss/isa/instruction_type_r.h"

InstructionTypeR::InstructionTypeR(Opcode opcode, Register rd, Register rs1, Register rs2)
    : Instruction(opcode), rd(rd), rs1(rs1), rs2(rs2) {}

InstructionTypeR::~InstructionTypeR() = default;
