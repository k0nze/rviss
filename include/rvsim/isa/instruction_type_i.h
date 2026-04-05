#ifndef RVSIM_ISA_INSTRUCTION_TYPE_I_H
#define RVSIM_ISA_INSTRUCTION_TYPE_I_H

#include "rvsim/isa/instruction.h"
#include "rvsim/isa/opcode.h"
#include "rvsim/isa/register.h"
#include <cstdint>

class InstructionTypeI: public Instruction {
public:
    virtual ~InstructionTypeI() = 0;
    Register rd;
    Register rs1;
    uint32_t imm;

protected:
    InstructionTypeI(Opcode opcode, Register rd, Register rs1, uint32_t imm);
};

#endif
