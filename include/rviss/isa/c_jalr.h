#ifndef RVISS_ISA_C_JALR_H
#define RVISS_ISA_C_JALR_H

#include "rviss/isa/instruction_type_cr.h"

class C_JALR : public InstructionTypeCR {
public:
    C_JALR(Register rs1);
};

#endif
