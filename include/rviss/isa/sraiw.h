#ifndef RVISS_ISA_SRAIW_H
#define RVISS_ISA_SRAIW_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class SRAIW : public InstructionTypeI {
public:
    SRAIW(Register rd, Register rs, uint32_t imm);
};

#endif
