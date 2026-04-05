#ifndef RVSIM_ISA_LUI_H
#define RVSIM_ISA_LUI_H

#include "rvsim/isa/instruction.h"
#include "rvsim/isa/register.h"
#include <cstdint>

class LUI : public Instruction {
public:
    LUI(Register rd, uint32_t imm);

    Register rd;
    uint32_t imm;
};

#endif
