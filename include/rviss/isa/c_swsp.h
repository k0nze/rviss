#ifndef RVISS_ISA_C_SWSP_H
#define RVISS_ISA_C_SWSP_H

#include "rviss/isa/instruction_type_css.h"
#include <cstdint>

class C_SWSP : public InstructionTypeCSS {
public:
    C_SWSP(Register rs2, uint16_t imm);
};

#endif
