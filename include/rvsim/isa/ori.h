#ifndef RVSIM_ISA_ORI_H
#define RVSIM_ISA_ORI_H

#include "rvsim/isa/instruction_type_i.h"
#include <cstdint>

class ORI : public InstructionTypeI {
public:
    ORI(Register rd, Register rs, uint32_t imm);
};

#endif
