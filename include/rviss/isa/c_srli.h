#ifndef RVISS_ISA_C_SRLI_H
#define RVISS_ISA_C_SRLI_H

#include "rviss/isa/instruction_type_cb.h"
#include <cstdint>

class C_SRLI : public InstructionTypeCB {
public:
    C_SRLI(Register rs1, uint16_t imm);
};

#endif
