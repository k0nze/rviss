#ifndef RVISS_ISA_AMOMIN_D_H
#define RVISS_ISA_AMOMIN_D_H

#include "rviss/isa/instruction_type_r.h"

class AMOMIN_D : public InstructionTypeR {
public:
    AMOMIN_D(Register rd, Register rs1, Register rs2);
};

#endif
