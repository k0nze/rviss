#ifndef RVISS_ISA_C_SUBW_H
#define RVISS_ISA_C_SUBW_H

#include "rviss/isa/instruction_type_ca.h"

class C_SUBW : public InstructionTypeCA {
public:
    C_SUBW(Register rd_rs1, Register rs2);
};

#endif
