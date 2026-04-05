#ifndef RVISS_ISA_FENCE_H
#define RVISS_ISA_FENCE_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class FENCE : public InstructionTypeI {
public:
    explicit FENCE(uint32_t imm);
};

#endif
