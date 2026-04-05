#ifndef RVISS_ISA_CSRRWI_H
#define RVISS_ISA_CSRRWI_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class CSRRWI : public InstructionTypeI {
public:
    CSRRWI(Register rd, Register rs, uint16_t imm);
};

#endif
