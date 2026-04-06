#ifndef RVISS_ISA_AMOXOR_W_H
#define RVISS_ISA_AMOXOR_W_H

#include "rviss/isa/instruction_type_amo.h"

class AMOXOR_W : public InstructionTypeAMO {
public:
    AMOXOR_W(Register rd, Register rs1, Register rs2);
};

#endif
