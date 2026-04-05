#ifndef RVISS_ISA_SLLW_H
#define RVISS_ISA_SLLW_H

#include "rviss/isa/instruction_type_r.h"

class SLLW : public InstructionTypeR {
public:
    SLLW(Register rd, Register rs1, Register rs2);
};

#endif
