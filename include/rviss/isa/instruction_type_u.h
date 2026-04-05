#ifndef RVISS_ISA_INSTRUCTION_TYPE_U_H
#define RVISS_ISA_INSTRUCTION_TYPE_U_H

#include "rviss/isa/instruction.h"
#include "rviss/isa/opcode.h"
#include "rviss/isa/register.h"
#include <cstdint>

class InstructionTypeU: public Instruction {
public:
    virtual ~InstructionTypeU() = 0;
    Register rd;
    uint32_t imm;

protected:
    InstructionTypeU(Opcode opcode, Register rd, uint32_t imm);
};

#endif
