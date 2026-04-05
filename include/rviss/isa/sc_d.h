#ifndef RVISS_ISA_SC_D_H
#define RVISS_ISA_SC_D_H

#include "rviss/isa/instruction_type_r.h"

class SC_D : public InstructionTypeR {
public:
    SC_D(Register rd, Register rs1, Register rs2);
};

#endif
