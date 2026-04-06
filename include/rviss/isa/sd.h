#ifndef RVISS_ISA_SD_H
#define RVISS_ISA_SD_H

#include "rviss/isa/instruction_type_s.h"
#include <cstdint>

class SD : public InstructionTypeS {
public:
    SD(Register rs1, Register rs2, uint16_t imm);
};

#endif
