#ifndef RVSIM_ISA_INSTRUCTION_H
#define RVSIM_ISA_INSTRUCTION_H

#include "rvsim/isa/opcode.h"

class Instruction {
public:
    Instruction(Opcode opcode);
    Opcode opcode;
};

#endif
