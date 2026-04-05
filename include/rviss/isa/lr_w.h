#ifndef RVISS_ISA_LR_W_H
#define RVISS_ISA_LR_W_H

#include "rviss/isa/instruction_type_r.h"

class LR_W : public InstructionTypeR {
public:
    LR_W(Register rd, Register rs1);
};

#endif
