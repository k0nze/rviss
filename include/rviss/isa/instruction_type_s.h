#ifndef RVISS_ISA_INSTRUCTION_TYPE_S_H
#define RVISS_ISA_INSTRUCTION_TYPE_S_H

#include "rviss/isa/instruction.h"
#include "rviss/isa/opcode.h"
#include "rviss/isa/register.h"
#include <cstdint>

class InstructionTypeS: public Instruction {
public:
    virtual ~InstructionTypeS() = 0;
    Register rs1;
    Register rs2;
    uint16_t imm;

protected:
    InstructionTypeS(Opcode opcode, Register rs1, Register rs2, uint16_t imm);
};

#endif
