#ifndef RVISS_ISA_AMOSWAP_W_H
#define RVISS_ISA_AMOSWAP_W_H

#include "rviss/isa/instruction_type_r.h"

class AMOSWAP_W : public InstructionTypeR {
public:
    AMOSWAP_W(Register rd, Register rs1, Register rs2);
};

#endif
