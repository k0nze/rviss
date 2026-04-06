#ifndef RVISS_ISA_INSTRUCTION_TYPE_CI_H
#define RVISS_ISA_INSTRUCTION_TYPE_CI_H

#include "rviss/isa/instruction.h"
#include "rviss/isa/opcode.h"
#include "rviss/isa/register.h"
#include <cstdint>

class InstructionTypeCI: public Instruction {
public:
    virtual ~InstructionTypeCI() = 0;
    Register rd_rs1;
    uint16_t imm;

protected:
    InstructionTypeCI(Opcode opcode, Register rd_rs1, uint16_t imm);
};

#endif
