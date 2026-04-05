#ifndef RVSIM_ISA_SLTIU_H
#define RVSIM_ISA_SLTIU_H

#include "rvsim/isa/instruction_type_i.h"
#include <cstdint>

class SLTIU : public InstructionTypeI {
public:
    SLTIU(Register rd, Register rs, uint32_t imm);
};

#endif
