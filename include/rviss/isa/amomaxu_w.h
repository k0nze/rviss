#ifndef RVISS_ISA_AMOMAXU_W_H
#define RVISS_ISA_AMOMAXU_W_H

#include "rviss/isa/instruction_type_r.h"

class AMOMAXU_W : public InstructionTypeR {
public:
    AMOMAXU_W(Register rd, Register rs1, Register rs2);
};

#endif
