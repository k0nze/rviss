#ifndef RVISS_ISA_C_BEQZ_H
#define RVISS_ISA_C_BEQZ_H

#include "rviss/isa/instruction_type_cb.h"
#include <cstdint>

class C_BEQZ : public InstructionTypeCB {
public:
    C_BEQZ(Register rs1, uint16_t imm);
};

#endif
