#ifndef RVISS_ISA_SUBW_H
#define RVISS_ISA_SUBW_H

#include "rviss/isa/instruction_type_r.h"

class SUBW : public InstructionTypeR {
public:
    SUBW(Register rd, Register rs1, Register rs2);
};

#endif
