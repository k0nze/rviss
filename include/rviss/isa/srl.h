#ifndef RVISS_ISA_SRL_H
#define RVISS_ISA_SRL_H

#include "rviss/isa/instruction_type_r.h"

class SRL : public InstructionTypeR {
public:
    SRL(Register rd, Register rs1, Register rs2);
};

#endif
