#ifndef RVISS_ISA_C_ADDI_H
#define RVISS_ISA_C_ADDI_H

#include "rviss/isa/instruction_type_ci.h"
#include <cstdint>

class C_ADDI : public InstructionTypeCI {
public:
    C_ADDI(Register rd_rs1, uint16_t imm);
};

#endif
