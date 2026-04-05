#ifndef RVISS_ISA_LBU_H
#define RVISS_ISA_LBU_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class LBU : public InstructionTypeI {
public:
    LBU(Register rd, Register rs, uint16_t imm);
};

#endif
