#ifndef RVISS_ISA_INSTRUCTION_TYPE_CA_H
#define RVISS_ISA_INSTRUCTION_TYPE_CA_H

#include "rviss/isa/instruction.h"
#include "rviss/isa/opcode.h"
#include "rviss/isa/register.h"

class InstructionTypeCA: public Instruction {
public:
    virtual ~InstructionTypeCA() = 0;
    Register rd_rs1;
    Register rs2;

protected:
    InstructionTypeCA(Opcode opcode, Register rd_rs1, Register rs2);
};

#endif
