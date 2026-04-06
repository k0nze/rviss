#ifndef RVISS_ISA_C_XOR_H
#define RVISS_ISA_C_XOR_H

#include "rviss/isa/instruction_type_ca.h"

class C_XOR : public InstructionTypeCA {
public:
    C_XOR(Register rd_rs1, Register rs2);
};

#endif
