#ifndef RVISS_ISA_SUB_H
#define RVISS_ISA_SUB_H

#include "rviss/isa/instruction_type_r.h"

class SUB : public InstructionTypeR {
public:
    SUB(Register rd, Register rs1, Register rs2);
};

#endif
