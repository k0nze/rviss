#ifndef RVISS_ISA_JALR_H
#define RVISS_ISA_JALR_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class JALR : public InstructionTypeI {
public:
    JALR(Register rd, Register rs, uint16_t imm);
};

#endif
