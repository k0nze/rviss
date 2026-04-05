#ifndef RVISS_ISA_LUI_H
#define RVISS_ISA_LUI_H

#include "rviss/isa/instruction.h"
#include "rviss/isa/register.h"
#include <cstdint>

class LUI : public Instruction {
public:
    LUI(Register rd, uint32_t imm);

    Register rd;
    uint32_t imm;
};

#endif
