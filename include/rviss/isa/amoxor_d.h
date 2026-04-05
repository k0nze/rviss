#ifndef RVISS_ISA_AMOXOR_D_H
#define RVISS_ISA_AMOXOR_D_H

#include "rviss/isa/instruction_type_r.h"

class AMOXOR_D : public InstructionTypeR {
public:
    AMOXOR_D(Register rd, Register rs1, Register rs2);
};

#endif
