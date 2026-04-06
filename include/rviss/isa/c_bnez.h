#ifndef RVISS_ISA_C_BNEZ_H
#define RVISS_ISA_C_BNEZ_H

#include "rviss/isa/instruction_type_cb.h"
#include <cstdint>

class C_BNEZ : public InstructionTypeCB {
public:
    C_BNEZ(Register rs1, uint16_t imm);
};

#endif
