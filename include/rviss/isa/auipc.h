#ifndef RVISS_ISA_AUIPC_H
#define RVISS_ISA_AUIPC_H

#include "rviss/isa/instruction_type_u.h"

class AUIPC : public InstructionTypeU {
public:
    AUIPC(Register rd, uint32_t imm);
};

#endif
