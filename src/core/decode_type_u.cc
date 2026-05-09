#include "decoder_internal.h"

#include "rviss/isa/auipc.h"
#include "rviss/isa/lui.h"
#include "rviss/isa/register.h"

namespace {

Register decode_register(uint32_t bits) {
    return static_cast<Register>(bits & 0x1fU);
}

uint32_t decode_u_immediate(uint32_t encoded_instruction) {
    return encoded_instruction >> 12U;
}

}

std::unique_ptr<Instruction> decode_type_u(uint32_t encoded_instruction) {
    const Register rd = decode_register(encoded_instruction >> 7U);
    const uint32_t imm = decode_u_immediate(encoded_instruction);

    switch (encoded_instruction & 0x7fU) {
    case 0x37U:
        return std::make_unique<LUI>(rd, imm);
    case 0x17U:
        return std::make_unique<AUIPC>(rd, imm);
    default:
        return nullptr;
    }
}
