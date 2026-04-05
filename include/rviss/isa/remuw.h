#ifndef RVISS_ISA_REMUW_H
#define RVISS_ISA_REMUW_H

#include "rviss/isa/instruction_type_r.h"

class REMUW : public InstructionTypeR {
public:
    REMUW(Register rd, Register rs1, Register rs2);
};

#endif
