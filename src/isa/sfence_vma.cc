#include "rviss/isa/sfence_vma.h"

SFENCE_VMA::SFENCE_VMA(Register rs1, Register rs2)
    : InstructionTypeI(Opcode::SFENCE_VMA, Register::zero, rs1, 0), rs2(rs2) {}
