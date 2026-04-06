#ifndef RVISS_ISA_C_ADDIW_H
#define RVISS_ISA_C_ADDIW_H

#include "rviss/isa/instruction_type_ci.h"
#include <cstdint>

class C_ADDIW : public InstructionTypeCI {
public:
    C_ADDIW(Register rd_rs1, uint16_t imm);
};

#endif
