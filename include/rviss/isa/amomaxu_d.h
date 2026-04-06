#ifndef RVISS_ISA_AMOMAXU_D_H
#define RVISS_ISA_AMOMAXU_D_H

#include "rviss/isa/instruction_type_amo.h"

class AMOMAXU_D : public InstructionTypeAMO {
public:
    AMOMAXU_D(Register rd, Register rs1, Register rs2);
};

#endif
