#ifndef RVISS_ISA_ORI_H
#define RVISS_ISA_ORI_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class ORI : public InstructionTypeI {
public:
    ORI(Register rd, Register rs, uint16_t imm);
};

#endif
