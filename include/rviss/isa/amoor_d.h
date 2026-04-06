#ifndef RVISS_ISA_AMOOR_D_H
#define RVISS_ISA_AMOOR_D_H

#include "rviss/isa/instruction_type_amo.h"

class AMOOR_D : public InstructionTypeAMO {
public:
    AMOOR_D(Register rd, Register rs1, Register rs2);
};

#endif
