#ifndef RVISS_ISA_AMOMAX_W_H
#define RVISS_ISA_AMOMAX_W_H

#include "rviss/isa/instruction_type_r.h"

class AMOMAX_W : public InstructionTypeR {
public:
    AMOMAX_W(Register rd, Register rs1, Register rs2);
};

#endif
