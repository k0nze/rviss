#ifndef RVISS_ISA_SRLIW_H
#define RVISS_ISA_SRLIW_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class SRLIW : public InstructionTypeI {
public:
    SRLIW(Register rd, Register rs, uint16_t imm);
};

#endif
