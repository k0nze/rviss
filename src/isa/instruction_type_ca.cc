#include "rviss/isa/instruction_type_ca.h"

InstructionTypeCA::InstructionTypeCA(Opcode opcode, Register rd_rs1, Register rs2)
    : Instruction(opcode), rd_rs1(rd_rs1), rs2(rs2) {}

InstructionTypeCA::~InstructionTypeCA() = default;
