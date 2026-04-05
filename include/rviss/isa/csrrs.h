#ifndef RVISS_ISA_CSRRS_H
#define RVISS_ISA_CSRRS_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class CSRRS : public InstructionTypeI {
public:
    CSRRS(Register rd, Register rs, uint32_t imm);
};

#endif
