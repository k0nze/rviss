#ifndef RVISS_ISA_INSTRUCTION_TYPE_CL_H
#define RVISS_ISA_INSTRUCTION_TYPE_CL_H

#include "rviss/isa/instruction.h"
#include "rviss/isa/opcode.h"
#include "rviss/isa/register.h"
#include <cstdint>

class InstructionTypeCL: public Instruction {
public:
    virtual ~InstructionTypeCL() = 0;
    Register rd;
    Register rs1;
    uint16_t imm;

protected:
    InstructionTypeCL(Opcode opcode, Register rd, Register rs1, uint16_t imm);
};

#endif
