#ifndef RVISS_ISA_LW_H
#define RVISS_ISA_LW_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class LW : public InstructionTypeI {
public:
    LW(Register rd, Register rs, uint16_t imm);
};

#endif
