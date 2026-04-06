#ifndef RVISS_ISA_BGEU_H
#define RVISS_ISA_BGEU_H

#include "rviss/isa/instruction_type_b.h"

class BGEU : public InstructionTypeB {
public:
    BGEU(Register rs1, Register rs2, uint16_t imm);
};

#endif
