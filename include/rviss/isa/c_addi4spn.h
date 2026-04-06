#ifndef RVISS_ISA_C_ADDI4SPN_H
#define RVISS_ISA_C_ADDI4SPN_H

#include "rviss/isa/instruction_type_ciw.h"
#include <cstdint>

class C_ADDI4SPN : public InstructionTypeCIW {
public:
    C_ADDI4SPN(Register rd, uint16_t imm);
};

#endif
