#ifndef RVSIM_ISA_SLLI_H
#define RVSIM_ISA_SLLI_H

#include "rvsim/isa/instruction_type_i.h"
#include <cstdint>

class SLLI : public InstructionTypeI {
public:
    SLLI(Register rd, Register rs, uint32_t imm);
};

#endif
