#ifndef RVISS_ISA_AMOMAX_D_H
#define RVISS_ISA_AMOMAX_D_H

#include "rviss/isa/instruction_type_r.h"

class AMOMAX_D : public InstructionTypeR {
public:
    AMOMAX_D(Register rd, Register rs1, Register rs2);
};

#endif
