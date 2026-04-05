#ifndef RVISS_ISA_XORI_H
#define RVISS_ISA_XORI_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class XORI : public InstructionTypeI {
public:
    XORI(Register rd, Register rs, uint32_t imm);
};

#endif
