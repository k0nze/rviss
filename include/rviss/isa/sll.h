#ifndef RVISS_ISA_SLL_H
#define RVISS_ISA_SLL_H

#include "rviss/isa/instruction_type_r.h"

class SLL : public InstructionTypeR {
public:
    SLL(Register rd, Register rs1, Register rs2);
};

#endif
