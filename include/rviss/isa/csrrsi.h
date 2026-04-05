#ifndef RVISS_ISA_CSRRSI_H
#define RVISS_ISA_CSRRSI_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class CSRRSI : public InstructionTypeI {
public:
    CSRRSI(Register rd, Register rs, uint16_t imm);
};

#endif
