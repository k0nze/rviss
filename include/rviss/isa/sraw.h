#ifndef RVISS_ISA_SRAW_H
#define RVISS_ISA_SRAW_H

#include "rviss/isa/instruction_type_r.h"

class SRAW : public InstructionTypeR {
public:
    SRAW(Register rd, Register rs1, Register rs2);
};

#endif
