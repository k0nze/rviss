#include "rviss/isa/c_addi4spn.h"

C_ADDI4SPN::C_ADDI4SPN(Register rd, uint16_t imm)
    : InstructionTypeCIW(Opcode::C_ADDI4SPN, rd, imm) {}
