#ifndef RVISS_ISA_C_SDSP_H
#define RVISS_ISA_C_SDSP_H

#include "rviss/isa/instruction_type_css.h"
#include <cstdint>

class C_SDSP : public InstructionTypeCSS {
public:
    C_SDSP(Register rs2, uint16_t imm);
};

#endif
