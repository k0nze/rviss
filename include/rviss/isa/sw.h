#ifndef RVISS_ISA_SW_H
#define RVISS_ISA_SW_H

#include "rviss/isa/instruction_type_s.h"
#include <cstdint>

class SW : public InstructionTypeS {
public:
    SW(Register rs1, Register rs2, uint16_t imm);
};

#endif
