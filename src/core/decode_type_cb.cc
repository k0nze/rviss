#include "decoder_internal.h"

#include "rviss/isa/c_andi.h"
#include "rviss/isa/c_beqz.h"
#include "rviss/isa/c_bnez.h"
#include "rviss/isa/c_srai.h"
#include "rviss/isa/c_srli.h"
#include "rviss/isa/register.h"

namespace {

Register decode_compact_register(uint16_t bits) {
    return static_cast<Register>(8U + (bits & 0x7U));
}

uint16_t decode_cb_immediate(uint16_t encoded_instruction) {
    return static_cast<uint16_t>((((encoded_instruction >> 12U) & 0x1U) << 5U)
        | ((encoded_instruction >> 2U) & 0x1fU));
}

uint16_t decode_cb_branch_immediate(uint16_t encoded_instruction) {
    return static_cast<uint16_t>((((encoded_instruction >> 12U) & 0x1U) << 8U)
        | (((encoded_instruction >> 5U) & 0x3U) << 6U)
        | (((encoded_instruction >> 2U) & 0x1U) << 5U)
        | (((encoded_instruction >> 10U) & 0x3U) << 3U)
        | (((encoded_instruction >> 3U) & 0x3U) << 1U));
}

}

std::unique_ptr<Instruction> decode_type_cb(uint16_t encoded_instruction) {
    const uint16_t funct3 = static_cast<uint16_t>((encoded_instruction >> 13U) & 0x7U);
    const Register rs1 = decode_compact_register(static_cast<uint16_t>(encoded_instruction >> 7U));

    switch (funct3) {
    case 0b100U: {
        const uint16_t subop = static_cast<uint16_t>((encoded_instruction >> 10U) & 0x3U);
        const uint16_t imm = decode_cb_immediate(encoded_instruction);

        switch (subop) {
        case 0b00U:
            return std::make_unique<C_SRLI>(rs1, imm);
        case 0b01U:
            return std::make_unique<C_SRAI>(rs1, imm);
        case 0b10U:
            return std::make_unique<C_ANDI>(rs1, imm);
        default:
            return nullptr;
        }
    }
    case 0b110U:
        return std::make_unique<C_BEQZ>(rs1, decode_cb_branch_immediate(encoded_instruction));
    case 0b111U:
        return std::make_unique<C_BNEZ>(rs1, decode_cb_branch_immediate(encoded_instruction));
    default:
        return nullptr;
    }
}
