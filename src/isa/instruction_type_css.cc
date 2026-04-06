#include "rviss/isa/instruction_type_css.h"

InstructionTypeCSS::InstructionTypeCSS(Opcode opcode, Register rs2, uint16_t imm)
    : Instruction(opcode), rs2(rs2), imm(imm) {}

InstructionTypeCSS::~InstructionTypeCSS() = default;
