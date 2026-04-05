#ifndef RVISS_ISA_ADDI_H
#define RVISS_ISA_ADDI_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class ADDI : public InstructionTypeI {
public:
    ADDI(Register rd, Register rs, uint16_t imm);
};

#endif
