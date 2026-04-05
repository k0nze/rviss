#ifndef RVSIM_ISA_ADDI_H
#define RVSIM_ISA_ADDI_H

#include "rvsim/isa/instruction_type_i.h"
#include <cstdint>

class ADDI : public InstructionTypeI {
public:
    ADDI(Register rd, Register rs, uint32_t imm);
};

#endif
