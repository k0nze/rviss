#ifndef RVISS_ISA_CSRRC_H
#define RVISS_ISA_CSRRC_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class CSRRC : public InstructionTypeI {
public:
    CSRRC(Register rd, Register rs, uint32_t imm);
};

#endif
