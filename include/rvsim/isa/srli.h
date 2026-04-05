#ifndef RVSIM_ISA_SRLI_H
#define RVSIM_ISA_SRLI_H

#include "rvsim/isa/instruction_type_i.h"
#include <cstdint>

class SRLI : public InstructionTypeI {
public:
    SRLI(Register rd, Register rs, uint32_t imm);
};

#endif
