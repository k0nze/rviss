#ifndef RVISS_ISA_MULHU_H
#define RVISS_ISA_MULHU_H

#include "rviss/isa/instruction_type_r.h"

class MULHU : public InstructionTypeR {
public:
    MULHU(Register rd, Register rs1, Register rs2);
};

#endif
