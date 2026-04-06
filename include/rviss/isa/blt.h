#ifndef RVISS_ISA_BLT_H
#define RVISS_ISA_BLT_H

#include "rviss/isa/instruction_type_b.h"

class BLT : public InstructionTypeB {
public:
    BLT(Register rs1, Register rs2, uint16_t imm);
};

#endif
