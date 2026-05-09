#include "decoder_internal.h"

#include "rviss/isa/register.h"
#include "rviss/isa/sb.h"
#include "rviss/isa/sd.h"
#include "rviss/isa/sh.h"
#include "rviss/isa/sw.h"

namespace {

Register decode_register(uint32_t bits) {
    return static_cast<Register>(bits & 0x1fU);
}

uint16_t decode_s_immediate(uint32_t encoded_instruction) {
    const uint16_t bits4_0 = static_cast<uint16_t>((encoded_instruction >> 7U) & 0x1fU);
    const uint16_t bits11_5 = static_cast<uint16_t>(((encoded_instruction >> 25U) & 0x7fU) << 5U);

    return static_cast<uint16_t>(bits11_5 | bits4_0);
}

}

std::unique_ptr<Instruction> decode_type_s(uint32_t encoded_instruction) {
    const Register rs1 = decode_register(encoded_instruction >> 15U);
    const Register rs2 = decode_register(encoded_instruction >> 20U);
    const uint16_t imm = decode_s_immediate(encoded_instruction);

    switch ((encoded_instruction >> 12U) & 0x7U) {
    case 0b000U:
        return std::make_unique<SB>(rs1, rs2, imm);
    case 0b001U:
        return std::make_unique<SH>(rs1, rs2, imm);
    case 0b010U:
        return std::make_unique<SW>(rs1, rs2, imm);
    case 0b011U:
        return std::make_unique<SD>(rs1, rs2, imm);
    default:
        return nullptr;
    }
}
