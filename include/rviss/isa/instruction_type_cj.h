#ifndef RVISS_ISA_INSTRUCTION_TYPE_CJ_H
#define RVISS_ISA_INSTRUCTION_TYPE_CJ_H

#include "rviss/isa/instruction.h"
#include "rviss/isa/opcode.h"
#include <cstdint>

class InstructionTypeCJ: public Instruction {
public:
    virtual ~InstructionTypeCJ() = 0;
    uint16_t imm;

protected:
    InstructionTypeCJ(Opcode opcode, uint16_t imm);
};

#endif
