#ifndef RVISS_ISA_BNE_H
#define RVISS_ISA_BNE_H

#include "rviss/isa/instruction_type_b.h"

class BNE : public InstructionTypeB {
public:
    BNE(Register rs1, Register rs2, uint16_t imm);
};

#endif
