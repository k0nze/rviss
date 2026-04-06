#ifndef RVISS_ISA_INSTRUCTION_TYPE_B_H
#define RVISS_ISA_INSTRUCTION_TYPE_B_H

#include "rviss/isa/instruction.h"
#include "rviss/isa/opcode.h"
#include "rviss/isa/register.h"
#include <cstdint>

class InstructionTypeB: public Instruction {
public:
    virtual ~InstructionTypeB() = 0;
    Register rs1;
    Register rs2;
    uint16_t imm;

protected:
    InstructionTypeB(Opcode opcode, Register rs1, Register rs2, uint16_t imm);
};

#endif
