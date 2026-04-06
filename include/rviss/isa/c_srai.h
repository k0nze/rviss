#ifndef RVISS_ISA_C_SRAI_H
#define RVISS_ISA_C_SRAI_H

#include "rviss/isa/instruction_type_cb.h"
#include <cstdint>

class C_SRAI : public InstructionTypeCB {
public:
    C_SRAI(Register rs1, uint16_t imm);
};

#endif
