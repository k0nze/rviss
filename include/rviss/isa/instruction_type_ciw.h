#ifndef RVISS_ISA_INSTRUCTION_TYPE_CIW_H
#define RVISS_ISA_INSTRUCTION_TYPE_CIW_H

#include "rviss/isa/instruction.h"
#include "rviss/isa/opcode.h"
#include "rviss/isa/register.h"
#include <cstdint>

class InstructionTypeCIW: public Instruction {
public:
    virtual ~InstructionTypeCIW() = 0;
    Register rd;
    uint16_t imm;

protected:
    InstructionTypeCIW(Opcode opcode, Register rd, uint16_t imm);
};

#endif
