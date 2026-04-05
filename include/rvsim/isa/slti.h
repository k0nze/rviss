#ifndef RVSIM_ISA_SLTI_H
#define RVSIM_ISA_SLTI_H

#include "rvsim/isa/instruction_type_i.h"
#include <cstdint>

class SLTI : public InstructionTypeI {
public:
    SLTI(Register rd, Register rs, uint32_t imm);
};

#endif
