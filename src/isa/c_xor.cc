#include "rviss/isa/c_xor.h"

C_XOR::C_XOR(Register rd_rs1, Register rs2)
    : InstructionTypeCA(Opcode::C_XOR, rd_rs1, rs2) {}
