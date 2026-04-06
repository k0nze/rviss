#ifndef RVISS_ISA_SH_H
#define RVISS_ISA_SH_H

#include "rviss/isa/instruction_type_s.h"
#include <cstdint>

class SH : public InstructionTypeS {
public:
    SH(Register rs1, Register rs2, uint16_t imm);
};

#endif
