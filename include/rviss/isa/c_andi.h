#ifndef RVISS_ISA_C_ANDI_H
#define RVISS_ISA_C_ANDI_H

#include "rviss/isa/instruction_type_cb.h"
#include <cstdint>

class C_ANDI : public InstructionTypeCB {
public:
    C_ANDI(Register rs1, uint16_t imm);
};

#endif
