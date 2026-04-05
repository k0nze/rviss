#ifndef RVISS_ISA_SLTI_H
#define RVISS_ISA_SLTI_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class SLTI : public InstructionTypeI {
public:
    SLTI(Register rd, Register rs, uint16_t imm);
};

#endif
