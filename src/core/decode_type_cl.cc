#include "decoder_internal.h"

#include "rviss/isa/c_ld.h"
#include "rviss/isa/c_lw.h"
#include "rviss/isa/register.h"

namespace {

Register decode_compact_register(uint16_t bits) {
    return static_cast<Register>(8U + (bits & 0x7U));
}

uint16_t decode_cl_lw_immediate(uint16_t encoded_instruction) {
    return static_cast<uint16_t>((((encoded_instruction >> 5U) & 0x1U) << 6U)
        | (((encoded_instruction >> 10U) & 0x7U) << 3U)
        | (((encoded_instruction >> 6U) & 0x1U) << 2U));
}

uint16_t decode_cl_ld_immediate(uint16_t encoded_instruction) {
    return static_cast<uint16_t>((((encoded_instruction >> 5U) & 0x3U) << 6U)
        | (((encoded_instruction >> 10U) & 0x7U) << 3U));
}

}

std::unique_ptr<Instruction> decode_type_cl(uint16_t encoded_instruction) {
    const uint16_t funct3 = static_cast<uint16_t>((encoded_instruction >> 13U) & 0x7U);
    const Register rs1 = decode_compact_register(static_cast<uint16_t>(encoded_instruction >> 7U));
    const Register rd = decode_compact_register(static_cast<uint16_t>(encoded_instruction >> 2U));

    switch (funct3) {
    case 0b010U:
        return std::make_unique<C_LW>(rd, rs1, decode_cl_lw_immediate(encoded_instruction));
    case 0b011U:
        return std::make_unique<C_LD>(rd, rs1, decode_cl_ld_immediate(encoded_instruction));
    default:
        return nullptr;
    }
}
