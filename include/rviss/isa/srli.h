#ifndef RVISS_ISA_SRLI_H
#define RVISS_ISA_SRLI_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class SRLI : public InstructionTypeI {
public:
    SRLI(Register rd, Register rs, uint16_t imm);
};

#endif
