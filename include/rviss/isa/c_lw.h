#ifndef RVISS_ISA_C_LW_H
#define RVISS_ISA_C_LW_H

#include "rviss/isa/instruction_type_cl.h"
#include <cstdint>

class C_LW : public InstructionTypeCL {
public:
    C_LW(Register rd, Register rs1, uint16_t imm);
};

#endif
