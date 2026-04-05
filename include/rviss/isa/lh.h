#ifndef RVISS_ISA_LH_H
#define RVISS_ISA_LH_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class LH : public InstructionTypeI {
public:
    LH(Register rd, Register rs, uint32_t imm);
};

#endif
