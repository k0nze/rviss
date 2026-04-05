#ifndef RVISS_ISA_REMW_H
#define RVISS_ISA_REMW_H

#include "rviss/isa/instruction_type_r.h"

class REMW : public InstructionTypeR {
public:
    REMW(Register rd, Register rs1, Register rs2);
};

#endif
