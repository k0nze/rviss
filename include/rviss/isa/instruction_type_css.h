#ifndef RVISS_ISA_INSTRUCTION_TYPE_CSS_H
#define RVISS_ISA_INSTRUCTION_TYPE_CSS_H

#include "rviss/isa/instruction.h"
#include "rviss/isa/opcode.h"
#include "rviss/isa/register.h"
#include <cstdint>

class InstructionTypeCSS: public Instruction {
public:
    virtual ~InstructionTypeCSS() = 0;
    Register rs2;
    uint16_t imm;

protected:
    InstructionTypeCSS(Opcode opcode, Register rs2, uint16_t imm);
};

#endif
