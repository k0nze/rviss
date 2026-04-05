#ifndef RVISS_ISA_SLTIU_H
#define RVISS_ISA_SLTIU_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class SLTIU : public InstructionTypeI {
public:
    SLTIU(Register rd, Register rs, uint32_t imm);
};

#endif
