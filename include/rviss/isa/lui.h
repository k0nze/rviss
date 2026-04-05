#ifndef RVISS_ISA_LUI_H
#define RVISS_ISA_LUI_H

#include "rviss/isa/instruction_type_u.h"

class LUI : public InstructionTypeU {
public:
    LUI(Register rd, uint32_t imm);
};

#endif
