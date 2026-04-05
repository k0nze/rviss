#ifndef RVISS_ISA_LHU_H
#define RVISS_ISA_LHU_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class LHU : public InstructionTypeI {
public:
    LHU(Register rd, Register rs, uint32_t imm);
};

#endif
