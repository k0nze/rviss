#ifndef RVISS_ISA_BGE_H
#define RVISS_ISA_BGE_H

#include "rviss/isa/instruction_type_b.h"

class BGE : public InstructionTypeB {
public:
    BGE(Register rs1, Register rs2, uint16_t imm);
};

#endif
