#ifndef RVISS_ISA_AMOMINU_D_H
#define RVISS_ISA_AMOMINU_D_H

#include "rviss/isa/instruction_type_r.h"

class AMOMINU_D : public InstructionTypeR {
public:
    AMOMINU_D(Register rd, Register rs1, Register rs2);
};

#endif
