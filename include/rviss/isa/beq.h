#ifndef RVISS_ISA_BEQ_H
#define RVISS_ISA_BEQ_H

#include "rviss/isa/instruction_type_b.h"

class BEQ : public InstructionTypeB {
public:
    BEQ(Register rs1, Register rs2, uint16_t imm);
};

#endif
