#ifndef RVISS_ISA_INSTRUCTION_TYPE_CB_H
#define RVISS_ISA_INSTRUCTION_TYPE_CB_H

#include "rviss/isa/instruction.h"
#include "rviss/isa/opcode.h"
#include "rviss/isa/register.h"
#include <cstdint>

class InstructionTypeCB: public Instruction {
public:
    virtual ~InstructionTypeCB() = 0;
    Register rs1;
    uint16_t imm;

protected:
    InstructionTypeCB(Opcode opcode, Register rs1, uint16_t imm);
};

#endif
