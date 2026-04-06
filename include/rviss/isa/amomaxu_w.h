#ifndef RVISS_ISA_AMOMAXU_W_H
#define RVISS_ISA_AMOMAXU_W_H

#include "rviss/isa/instruction_type_amo.h"

class AMOMAXU_W : public InstructionTypeAMO {
public:
    AMOMAXU_W(Register rd, Register rs1, Register rs2);
};

#endif
