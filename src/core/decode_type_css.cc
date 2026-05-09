#include "decoder_internal.h"

#include "rviss/isa/c_sdsp.h"
#include "rviss/isa/c_swsp.h"
#include "rviss/isa/register.h"

namespace {

Register decode_register(uint16_t bits) {
    return static_cast<Register>(bits & 0x1fU);
}

uint16_t decode_css_swsp_immediate(uint16_t encoded_instruction) {
    return static_cast<uint16_t>((((encoded_instruction >> 9U) & 0xfU) << 2U)
        | (((encoded_instruction >> 7U) & 0x3U) << 6U));
}

uint16_t decode_css_sdsp_immediate(uint16_t encoded_instruction) {
    return static_cast<uint16_t>((((encoded_instruction >> 10U) & 0x7U) << 3U)
        | (((encoded_instruction >> 7U) & 0x7U) << 6U));
}

}

std::unique_ptr<Instruction> decode_type_css(uint16_t encoded_instruction) {
    const uint16_t funct3 = static_cast<uint16_t>((encoded_instruction >> 13U) & 0x7U);
    const Register rs2 = decode_register(static_cast<uint16_t>(encoded_instruction >> 2U));

    switch (funct3) {
    case 0b110U:
        return std::make_unique<C_SWSP>(rs2, decode_css_swsp_immediate(encoded_instruction));
    case 0b111U:
        return std::make_unique<C_SDSP>(rs2, decode_css_sdsp_immediate(encoded_instruction));
    default:
        return nullptr;
    }
}
