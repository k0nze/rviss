#ifndef RVISS_ISA_OR_H
#define RVISS_ISA_OR_H

#include "rviss/isa/instruction_type_r.h"

class OR : public InstructionTypeR {
public:
    OR(Register rd, Register rs1, Register rs2);
};

#endif
