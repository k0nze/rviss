#ifndef RVISS_ISA_C_MV_H
#define RVISS_ISA_C_MV_H

#include "rviss/isa/instruction_type_cr.h"

class C_MV : public InstructionTypeCR {
public:
    C_MV(Register rd, Register rs2);
};

#endif
