#ifndef RVISS_ISA_C_OR_H
#define RVISS_ISA_C_OR_H

#include "rviss/isa/instruction_type_ca.h"

class C_OR : public InstructionTypeCA {
public:
    C_OR(Register rd_rs1, Register rs2);
};

#endif
