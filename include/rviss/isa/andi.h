#ifndef RVISS_ISA_ANDI_H
#define RVISS_ISA_ANDI_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class ANDI : public InstructionTypeI {
public:
    ANDI(Register rd, Register rs, uint16_t imm);
};

#endif
