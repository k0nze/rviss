#ifndef RVISS_ISA_INSTRUCTION_TYPE_AMO_H
#define RVISS_ISA_INSTRUCTION_TYPE_AMO_H

#include "rviss/isa/instruction.h"
#include "rviss/isa/opcode.h"
#include "rviss/isa/register.h"

class InstructionTypeAMO: public Instruction {
public:
    virtual ~InstructionTypeAMO() = 0;
    Register rd;
    Register rs1;
    Register rs2;

protected:
    InstructionTypeAMO(Opcode opcode, Register rd, Register rs1, Register rs2);
};

#endif
