#ifndef RVISS_ISA_ADDIW_H
#define RVISS_ISA_ADDIW_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class ADDIW : public InstructionTypeI {
public:
    ADDIW(Register rd, Register rs, uint16_t imm);
};

#endif
