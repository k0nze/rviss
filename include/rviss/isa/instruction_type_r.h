#ifndef RVISS_ISA_INSTRUCTION_TYPE_R_H
#define RVISS_ISA_INSTRUCTION_TYPE_R_H

#include "rviss/isa/instruction.h"
#include "rviss/isa/opcode.h"
#include "rviss/isa/register.h"

class InstructionTypeR: public Instruction {
public:
    virtual ~InstructionTypeR() = 0;
    Register rd;
    Register rs1;
    Register rs2;

protected:
    InstructionTypeR(Opcode opcode, Register rd, Register rs1, Register rs2);
};

#endif
