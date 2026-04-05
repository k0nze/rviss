#ifndef RVISS_ISA_MULW_H
#define RVISS_ISA_MULW_H

#include "rviss/isa/instruction_type_r.h"

class MULW : public InstructionTypeR {
public:
    MULW(Register rd, Register rs1, Register rs2);
};

#endif
