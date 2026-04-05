#ifndef RVISS_ISA_AND_H
#define RVISS_ISA_AND_H

#include "rviss/isa/instruction_type_r.h"

class AND : public InstructionTypeR {
public:
    AND(Register rd, Register rs1, Register rs2);
};

#endif
