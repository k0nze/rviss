#ifndef RVISS_ISA_AMOSWAP_D_H
#define RVISS_ISA_AMOSWAP_D_H

#include "rviss/isa/instruction_type_r.h"

class AMOSWAP_D : public InstructionTypeR {
public:
    AMOSWAP_D(Register rd, Register rs1, Register rs2);
};

#endif
