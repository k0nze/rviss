#ifndef RVISS_ISA_SRLW_H
#define RVISS_ISA_SRLW_H

#include "rviss/isa/instruction_type_r.h"

class SRLW : public InstructionTypeR {
public:
    SRLW(Register rd, Register rs1, Register rs2);
};

#endif
