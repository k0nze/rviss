#ifndef RVISS_ISA_LR_D_H
#define RVISS_ISA_LR_D_H

#include "rviss/isa/instruction_type_r.h"

class LR_D : public InstructionTypeR {
public:
    LR_D(Register rd, Register rs1);
};

#endif
