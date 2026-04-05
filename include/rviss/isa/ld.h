#ifndef RVISS_ISA_LD_H
#define RVISS_ISA_LD_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class LD : public InstructionTypeI {
public:
    LD(Register rd, Register rs, uint32_t imm);
};

#endif
