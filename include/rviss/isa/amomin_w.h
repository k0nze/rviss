#ifndef RVISS_ISA_AMOMIN_W_H
#define RVISS_ISA_AMOMIN_W_H

#include "rviss/isa/instruction_type_r.h"

class AMOMIN_W : public InstructionTypeR {
public:
    AMOMIN_W(Register rd, Register rs1, Register rs2);
};

#endif
