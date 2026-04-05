#ifndef RVISS_ISA_INSTRUCTION_H
#define RVISS_ISA_INSTRUCTION_H

#include "rviss/isa/opcode.h"

class Instruction {
public:
    virtual ~Instruction() = 0;
    Opcode opcode;

protected:
    Instruction(Opcode opcode);
};

#endif
