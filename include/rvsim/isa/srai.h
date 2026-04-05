#ifndef RVSIM_ISA_SRAI_H
#define RVSIM_ISA_SRAI_H

#include "rvsim/isa/instruction_type_i.h"
#include <cstdint>

class SRAI : public InstructionTypeI {
public:
    SRAI(Register rd, Register rs, uint32_t imm);
};

#endif
