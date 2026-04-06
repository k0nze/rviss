#ifndef RVISS_ISA_AMOADD_W_H
#define RVISS_ISA_AMOADD_W_H

#include "rviss/isa/instruction_type_amo.h"

class AMOADD_W : public InstructionTypeAMO {
public:
    AMOADD_W(Register rd, Register rs1, Register rs2);
};

#endif
