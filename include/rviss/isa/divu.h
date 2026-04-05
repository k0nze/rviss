#ifndef RVISS_ISA_DIVU_H
#define RVISS_ISA_DIVU_H

#include "rviss/isa/instruction_type_r.h"

class DIVU : public InstructionTypeR {
public:
    DIVU(Register rd, Register rs1, Register rs2);
};

#endif
