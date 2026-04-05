#ifndef RVISS_ISA_MULH_H
#define RVISS_ISA_MULH_H

#include "rviss/isa/instruction_type_r.h"

class MULH : public InstructionTypeR {
public:
    MULH(Register rd, Register rs1, Register rs2);
};

#endif
