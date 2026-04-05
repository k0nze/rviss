#include "rviss/isa/wfi.h"

WFI::WFI()
    : InstructionTypeI(Opcode::WFI, Register::zero, Register::zero, 261) {}
