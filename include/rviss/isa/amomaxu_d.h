#ifndef RVISS_ISA_AMOMAXU_D_H
#define RVISS_ISA_AMOMAXU_D_H

#include "rviss/isa/instruction_type_r.h"

class AMOMAXU_D : public InstructionTypeR {
public:
    AMOMAXU_D(Register rd, Register rs1, Register rs2);
};

#endif
