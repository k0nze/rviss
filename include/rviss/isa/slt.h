#ifndef RVISS_ISA_SLT_H
#define RVISS_ISA_SLT_H

#include "rviss/isa/instruction_type_r.h"

class SLT : public InstructionTypeR {
public:
    SLT(Register rd, Register rs1, Register rs2);
};

#endif
