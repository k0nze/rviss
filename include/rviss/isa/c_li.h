#ifndef RVISS_ISA_C_LI_H
#define RVISS_ISA_C_LI_H

#include "rviss/isa/instruction_type_ci.h"
#include <cstdint>

class C_LI : public InstructionTypeCI {
public:
    C_LI(Register rd, uint16_t imm);
};

#endif
