#ifndef RVISS_ISA_AMOOR_D_H
#define RVISS_ISA_AMOOR_D_H

#include "rviss/isa/instruction_type_r.h"

class AMOOR_D : public InstructionTypeR {
public:
    AMOOR_D(Register rd, Register rs1, Register rs2);
};

#endif
