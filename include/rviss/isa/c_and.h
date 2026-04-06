#ifndef RVISS_ISA_C_AND_H
#define RVISS_ISA_C_AND_H

#include "rviss/isa/instruction_type_ca.h"

class C_AND : public InstructionTypeCA {
public:
    C_AND(Register rd_rs1, Register rs2);
};

#endif
