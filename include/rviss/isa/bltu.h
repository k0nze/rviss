#ifndef RVISS_ISA_BLTU_H
#define RVISS_ISA_BLTU_H

#include "rviss/isa/instruction_type_b.h"

class BLTU : public InstructionTypeB {
public:
    BLTU(Register rs1, Register rs2, uint16_t imm);
};

#endif
