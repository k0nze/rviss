#ifndef RVISS_ISA_INSTRUCTION_TYPE_J_H
#define RVISS_ISA_INSTRUCTION_TYPE_J_H

#include "rviss/isa/instruction.h"
#include "rviss/isa/opcode.h"
#include "rviss/isa/register.h"
#include <cstdint>

class InstructionTypeJ: public Instruction {
public:
    virtual ~InstructionTypeJ() = 0;
    Register rd;
    uint32_t imm;

protected:
    InstructionTypeJ(Opcode opcode, Register rd, uint32_t imm);
};

#endif
