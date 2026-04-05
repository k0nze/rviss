#ifndef RVISS_ISA_AMOAND_W_H
#define RVISS_ISA_AMOAND_W_H

#include "rviss/isa/instruction_type_r.h"

class AMOAND_W : public InstructionTypeR {
public:
    AMOAND_W(Register rd, Register rs1, Register rs2);
};

#endif
