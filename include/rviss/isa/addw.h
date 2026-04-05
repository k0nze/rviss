#ifndef RVISS_ISA_ADDW_H
#define RVISS_ISA_ADDW_H

#include "rviss/isa/instruction_type_r.h"

class ADDW : public InstructionTypeR {
public:
    ADDW(Register rd, Register rs1, Register rs2);
};

#endif
