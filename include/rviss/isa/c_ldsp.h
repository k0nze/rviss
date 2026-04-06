#ifndef RVISS_ISA_C_LDSP_H
#define RVISS_ISA_C_LDSP_H

#include "rviss/isa/instruction_type_ci.h"
#include <cstdint>

class C_LDSP : public InstructionTypeCI {
public:
    C_LDSP(Register rd, uint16_t imm);
};

#endif
