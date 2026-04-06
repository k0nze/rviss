#include "rviss/isa/auipc.h"

AUIPC::AUIPC(Register rd, uint32_t imm)
    : InstructionTypeU(Opcode::AUIPC, rd, imm) {}
