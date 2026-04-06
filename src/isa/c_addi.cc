#include "rviss/isa/c_addi.h"

C_ADDI::C_ADDI(Register rd_rs1, uint16_t imm)
    : InstructionTypeCI(Opcode::C_ADDI, rd_rs1, imm) {}
