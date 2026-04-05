#ifndef RVISS_ISA_LWU_H
#define RVISS_ISA_LWU_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class LWU : public InstructionTypeI {
public:
    LWU(Register rd, Register rs, uint32_t imm);
};

#endif
