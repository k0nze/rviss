#ifndef RVISS_ISA_DIVUW_H
#define RVISS_ISA_DIVUW_H

#include "rviss/isa/instruction_type_r.h"

class DIVUW : public InstructionTypeR {
public:
    DIVUW(Register rd, Register rs1, Register rs2);
};

#endif
