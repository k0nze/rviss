#ifndef RVISS_ISA_C_J_H
#define RVISS_ISA_C_J_H

#include "rviss/isa/instruction_type_cj.h"
#include <cstdint>

class C_J : public InstructionTypeCJ {
public:
    C_J(uint16_t imm);
};

#endif
