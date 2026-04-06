#ifndef RVISS_ISA_C_SLLI_H
#define RVISS_ISA_C_SLLI_H

#include "rviss/isa/instruction_type_ci.h"
#include <cstdint>

class C_SLLI : public InstructionTypeCI {
public:
    C_SLLI(Register rd_rs1, uint16_t imm);
};

#endif
