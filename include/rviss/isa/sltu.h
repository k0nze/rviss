#ifndef RVISS_ISA_SLTU_H
#define RVISS_ISA_SLTU_H

#include "rviss/isa/instruction_type_r.h"

class SLTU : public InstructionTypeR {
public:
    SLTU(Register rd, Register rs1, Register rs2);
};

#endif
