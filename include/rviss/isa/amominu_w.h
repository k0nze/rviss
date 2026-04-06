#ifndef RVISS_ISA_AMOMINU_W_H
#define RVISS_ISA_AMOMINU_W_H

#include "rviss/isa/instruction_type_amo.h"

class AMOMINU_W : public InstructionTypeAMO {
public:
    AMOMINU_W(Register rd, Register rs1, Register rs2);
};

#endif
