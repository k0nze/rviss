#ifndef RVISS_ISA_C_SUB_H
#define RVISS_ISA_C_SUB_H

#include "rviss/isa/instruction_type_ca.h"

class C_SUB : public InstructionTypeCA {
public:
    C_SUB(Register rd_rs1, Register rs2);
};

#endif
