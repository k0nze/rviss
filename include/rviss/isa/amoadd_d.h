#ifndef RVISS_ISA_AMOADD_D_H
#define RVISS_ISA_AMOADD_D_H

#include "rviss/isa/instruction_type_amo.h"

class AMOADD_D : public InstructionTypeAMO {
public:
    AMOADD_D(Register rd, Register rs1, Register rs2);
};

#endif
