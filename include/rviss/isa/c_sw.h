#ifndef RVISS_ISA_C_SW_H
#define RVISS_ISA_C_SW_H

#include "rviss/isa/instruction_type_cs.h"
#include <cstdint>

class C_SW : public InstructionTypeCS {
public:
    C_SW(Register rs1, Register rs2, uint16_t imm);
};

#endif
