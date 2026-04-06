#ifndef RVISS_ISA_C_LUI_H
#define RVISS_ISA_C_LUI_H

#include "rviss/isa/instruction_type_ci.h"
#include <cstdint>

class C_LUI : public InstructionTypeCI {
public:
    C_LUI(Register rd, uint16_t imm);
};

#endif
