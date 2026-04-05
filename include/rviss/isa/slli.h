#ifndef RVISS_ISA_SLLI_H
#define RVISS_ISA_SLLI_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class SLLI : public InstructionTypeI {
public:
    SLLI(Register rd, Register rs, uint32_t imm);
};

#endif
