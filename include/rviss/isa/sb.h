#ifndef RVISS_ISA_SB_H
#define RVISS_ISA_SB_H

#include "rviss/isa/instruction_type_s.h"
#include <cstdint>

class SB : public InstructionTypeS {
public:
    SB(Register rs1, Register rs2, uint16_t imm);
};

#endif
