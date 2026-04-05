#ifndef RVISS_ISA_AMOMINU_W_H
#define RVISS_ISA_AMOMINU_W_H

#include "rviss/isa/instruction_type_r.h"

class AMOMINU_W : public InstructionTypeR {
public:
    AMOMINU_W(Register rd, Register rs1, Register rs2);
};

#endif
