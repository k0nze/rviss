#ifndef RVSIM_ISA_INSTRUCTION_H
#define RVSIM_ISA_INSTRUCTION_H

#include "rvsim/isa/opcode.h"

class Instruction {
public:
    virtual ~Instruction() = 0;
    Opcode opcode;

protected:
    Instruction(Opcode opcode);
};

#endif
