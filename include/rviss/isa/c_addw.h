#ifndef RVISS_ISA_C_ADDW_H
#define RVISS_ISA_C_ADDW_H

#include "rviss/isa/instruction_type_ca.h"

class C_ADDW : public InstructionTypeCA {
public:
    C_ADDW(Register rd_rs1, Register rs2);
};

#endif
