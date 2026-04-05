#ifndef RVISS_ISA_AMOAND_D_H
#define RVISS_ISA_AMOAND_D_H

#include "rviss/isa/instruction_type_r.h"

class AMOAND_D : public InstructionTypeR {
public:
    AMOAND_D(Register rd, Register rs1, Register rs2);
};

#endif
