#ifndef RVISS_ISA_C_JR_H
#define RVISS_ISA_C_JR_H

#include "rviss/isa/instruction_type_cr.h"

class C_JR : public InstructionTypeCR {
public:
    C_JR(Register rs1);
};

#endif
