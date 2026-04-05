#ifndef RVISS_ISA_SC_W_H
#define RVISS_ISA_SC_W_H

#include "rviss/isa/instruction_type_r.h"

class SC_W : public InstructionTypeR {
public:
    SC_W(Register rd, Register rs1, Register rs2);
};

#endif
