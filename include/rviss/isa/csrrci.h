#ifndef RVISS_ISA_CSRRCI_H
#define RVISS_ISA_CSRRCI_H

#include "rviss/isa/instruction_type_i.h"
#include <cstdint>

class CSRRCI : public InstructionTypeI {
public:
    CSRRCI(Register rd, Register rs, uint16_t imm);
};

#endif
