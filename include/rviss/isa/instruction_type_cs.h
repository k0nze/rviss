#ifndef RVISS_ISA_INSTRUCTION_TYPE_CS_H
#define RVISS_ISA_INSTRUCTION_TYPE_CS_H

#include "rviss/isa/instruction.h"
#include "rviss/isa/opcode.h"
#include "rviss/isa/register.h"
#include <cstdint>

class InstructionTypeCS: public Instruction {
public:
    virtual ~InstructionTypeCS() = 0;
    Register rs1;
    Register rs2;
    uint16_t imm;

protected:
    InstructionTypeCS(Opcode opcode, Register rs1, Register rs2, uint16_t imm);
};

#endif
