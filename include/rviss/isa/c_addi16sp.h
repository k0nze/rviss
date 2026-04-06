#ifndef RVISS_ISA_C_ADDI16SP_H
#define RVISS_ISA_C_ADDI16SP_H

#include "rviss/isa/instruction_type_ci.h"
#include <cstdint>

class C_ADDI16SP : public InstructionTypeCI {
public:
    C_ADDI16SP(uint16_t imm);
};

#endif
