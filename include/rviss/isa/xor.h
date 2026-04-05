#ifndef RVISS_ISA_XOR_H
#define RVISS_ISA_XOR_H

#include "rviss/isa/instruction_type_r.h"

class XOR : public InstructionTypeR {
public:
    XOR(Register rd, Register rs1, Register rs2);
};

#endif
