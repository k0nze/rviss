#ifndef RVISS_ISA_AMOXOR_W_H
#define RVISS_ISA_AMOXOR_W_H

#include "rviss/isa/instruction_type_r.h"

class AMOXOR_W : public InstructionTypeR {
public:
    AMOXOR_W(Register rd, Register rs1, Register rs2);
};

#endif
