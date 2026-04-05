#ifndef RVISS_ISA_LB_H
#define RVISS_ISA_LB_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class LB : public InstructionTypeI {
public:
    LB(Register rd, Register rs, uint32_t imm);
};

#endif
