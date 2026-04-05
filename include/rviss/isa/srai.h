#ifndef RVISS_ISA_SRAI_H
#define RVISS_ISA_SRAI_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class SRAI : public InstructionTypeI {
public:
    SRAI(Register rd, Register rs, uint16_t imm);
};

#endif
