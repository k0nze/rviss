#ifndef RVISS_ISA_MUL_H
#define RVISS_ISA_MUL_H

#include "rviss/isa/instruction_type_r.h"

class MUL : public InstructionTypeR {
public:
    MUL(Register rd, Register rs1, Register rs2);
};

#endif
