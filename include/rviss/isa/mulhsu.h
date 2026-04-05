#ifndef RVISS_ISA_MULHSU_H
#define RVISS_ISA_MULHSU_H

#include "rviss/isa/instruction_type_r.h"

class MULHSU : public InstructionTypeR {
public:
    MULHSU(Register rd, Register rs1, Register rs2);
};

#endif
