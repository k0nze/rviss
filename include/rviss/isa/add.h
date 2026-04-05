#ifndef RVISS_ISA_ADD_H
#define RVISS_ISA_ADD_H

#include "rviss/isa/instruction_type_r.h"

class ADD : public InstructionTypeR {
public:
    ADD(Register rd, Register rs1, Register rs2);
};

#endif
