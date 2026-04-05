#ifndef RVSIM_ISA_XORI_H
#define RVSIM_ISA_XORI_H

#include "rvsim/isa/instruction_type_i.h"
#include <cstdint>

class XORI : public InstructionTypeI {
public:
    XORI(Register rd, Register rs, uint32_t imm);
};

#endif
