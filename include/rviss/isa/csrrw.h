#ifndef RVISS_ISA_CSRRW_H
#define RVISS_ISA_CSRRW_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class CSRRW : public InstructionTypeI {
public:
    CSRRW(Register rd, Register rs, uint16_t imm);
};

#endif
