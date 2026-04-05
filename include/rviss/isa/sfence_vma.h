#ifndef RVISS_ISA_SFENCE_VMA_H
#define RVISS_ISA_SFENCE_VMA_H

#include "rviss/isa/instruction_type_i.h"

class SFENCE_VMA : public InstructionTypeI {
public:
    SFENCE_VMA(Register rs1, Register rs2);

    Register rs2;
};

#endif
