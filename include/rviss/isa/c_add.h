#ifndef RVISS_ISA_C_ADD_H
#define RVISS_ISA_C_ADD_H

#include "rviss/isa/instruction_type_cr.h"

class C_ADD : public InstructionTypeCR {
public:
    C_ADD(Register rd, Register rs2);
};

#endif
