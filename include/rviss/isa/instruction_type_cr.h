#ifndef RVISS_ISA_INSTRUCTION_TYPE_CR_H
#define RVISS_ISA_INSTRUCTION_TYPE_CR_H

#include "rviss/isa/instruction.h"
#include "rviss/isa/opcode.h"
#include "rviss/isa/register.h"

class InstructionTypeCR: public Instruction {
public:
    virtual ~InstructionTypeCR() = 0;
    Register rd_rs1;
    Register rs2;

protected:
    InstructionTypeCR(Opcode opcode, Register rd_rs1, Register rs2);
};

#endif
