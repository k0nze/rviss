#include "rviss/isa/c_j.h"

C_J::C_J(uint16_t imm)
    : InstructionTypeCJ(Opcode::C_J, imm) {}
