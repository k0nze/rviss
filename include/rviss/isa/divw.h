#ifndef RVISS_ISA_DIVW_H
#define RVISS_ISA_DIVW_H

#include "rviss/isa/instruction_type_r.h"

class DIVW : public InstructionTypeR {
public:
    DIVW(Register rd, Register rs1, Register rs2);
};

#endif
