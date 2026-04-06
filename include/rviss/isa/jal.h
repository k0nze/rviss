#ifndef RVISS_ISA_JAL_H
#define RVISS_ISA_JAL_H

#include "rviss/isa/instruction_type_j.h"
#include <cstdint>

class JAL : public InstructionTypeJ {
public:
    JAL(Register rd, uint32_t imm);
};

#endif
