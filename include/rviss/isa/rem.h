#ifndef RVISS_ISA_REM_H
#define RVISS_ISA_REM_H

#include "rviss/isa/instruction_type_r.h"

class REM : public InstructionTypeR {
public:
    REM(Register rd, Register rs1, Register rs2);
};

#endif
