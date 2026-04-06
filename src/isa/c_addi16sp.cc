#include "rviss/isa/c_addi16sp.h"

C_ADDI16SP::C_ADDI16SP(uint16_t imm)
    : InstructionTypeCI(Opcode::C_ADDI16SP, Register::sp, imm) {}
