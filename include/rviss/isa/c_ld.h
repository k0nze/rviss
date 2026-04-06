#ifndef RVISS_ISA_C_LD_H
#define RVISS_ISA_C_LD_H

#include "rviss/isa/instruction_type_cl.h"
#include <cstdint>

class C_LD : public InstructionTypeCL {
public:
    C_LD(Register rd, Register rs1, uint16_t imm);
};

#endif
