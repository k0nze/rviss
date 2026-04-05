#ifndef RVISS_ISA_SLLIW_H
#define RVISS_ISA_SLLIW_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class SLLIW : public InstructionTypeI {
public:
    SLLIW(Register rd, Register rs, uint16_t imm);
};

#endif
