#ifndef RVISS_ISA_C_LWSP_H
#define RVISS_ISA_C_LWSP_H

#include "rviss/isa/instruction_type_ci.h"
#include <cstdint>

class C_LWSP : public InstructionTypeCI {
public:
    C_LWSP(Register rd, uint16_t imm);
};

#endif
