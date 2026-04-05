#ifndef RVISS_ISA_SRA_H
#define RVISS_ISA_SRA_H

#include "rviss/isa/instruction_type_r.h"

class SRA : public InstructionTypeR {
public:
    SRA(Register rd, Register rs1, Register rs2);
};

#endif
