#ifndef RVISS_ISA_DIV_H
#define RVISS_ISA_DIV_H

#include "rviss/isa/instruction_type_r.h"

class DIV : public InstructionTypeR {
public:
    DIV(Register rd, Register rs1, Register rs2);
};

#endif
