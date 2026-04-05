#ifndef RVSIM_ISA_ANDI_H
#define RVSIM_ISA_ANDI_H

#include "rvsim/isa/instruction_type_i.h"
#include <cstdint>

class ANDI : public InstructionTypeI {
public:
    ANDI(Register rd, Register rs, uint32_t imm);
};

#endif
