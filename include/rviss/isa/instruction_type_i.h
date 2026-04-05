#ifndef RVISS_ISA_INSTRUCTION_TYPE_I_H
#define RVISS_ISA_INSTRUCTION_TYPE_I_H

#include "rviss/isa/instruction.h"
#include "rviss/isa/opcode.h"
#include "rviss/isa/register.h"
#include <cstdint>

class InstructionTypeI: public Instruction {
public:
    virtual ~InstructionTypeI() = 0;
    Register rd;
    Register rs1;
    uint16_t imm;

protected:
    InstructionTypeI(Opcode opcode, Register rd, Register rs1, uint16_t imm);
};

#endif
