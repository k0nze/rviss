#ifndef RVISS_ISA_AMOOR_W_H
#define RVISS_ISA_AMOOR_W_H

#include "rviss/isa/instruction_type_amo.h"

class AMOOR_W : public InstructionTypeAMO {
public:
    AMOOR_W(Register rd, Register rs1, Register rs2);
};

#endif
