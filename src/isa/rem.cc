#include "rviss/isa/rem.h"

REM::REM(Register rd, Register rs1, Register rs2)
    : InstructionTypeR(Opcode::REM, rd, rs1, rs2) {}
