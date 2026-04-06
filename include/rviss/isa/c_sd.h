#ifndef RVISS_ISA_C_SD_H
#define RVISS_ISA_C_SD_H

#include "rviss/isa/instruction_type_cs.h"
#include <cstdint>

class C_SD : public InstructionTypeCS {
public:
    C_SD(Register rs1, Register rs2, uint16_t imm);
};

#endif
