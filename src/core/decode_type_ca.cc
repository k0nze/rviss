#include "decoder_internal.h"

#include "rviss/isa/c_addw.h"
#include "rviss/isa/c_and.h"
#include "rviss/isa/c_or.h"
#include "rviss/isa/c_sub.h"
#include "rviss/isa/c_subw.h"
#include "rviss/isa/c_xor.h"
#include "rviss/isa/register.h"

namespace {

Register decode_compact_register(uint16_t bits) {
    return static_cast<Register>(8U + (bits & 0x7U));
}

}

std::unique_ptr<Instruction> decode_type_ca(uint16_t encoded_instruction) {
    const Register rd_rs1 = decode_compact_register(static_cast<uint16_t>(encoded_instruction >> 7U));
    const Register rs2 = decode_compact_register(static_cast<uint16_t>(encoded_instruction >> 2U));
    const uint16_t bit12 = static_cast<uint16_t>((encoded_instruction >> 12U) & 0x1U);
    const uint16_t funct2 = static_cast<uint16_t>((encoded_instruction >> 5U) & 0x3U);

    if (bit12 == 0U) {
        switch (funct2) {
        case 0b00U:
            return std::make_unique<C_SUB>(rd_rs1, rs2);
        case 0b01U:
            return std::make_unique<C_XOR>(rd_rs1, rs2);
        case 0b10U:
            return std::make_unique<C_OR>(rd_rs1, rs2);
        case 0b11U:
            return std::make_unique<C_AND>(rd_rs1, rs2);
        default:
            return nullptr;
        }
    }

    switch (funct2) {
    case 0b00U:
        return std::make_unique<C_SUBW>(rd_rs1, rs2);
    case 0b01U:
        return std::make_unique<C_ADDW>(rd_rs1, rs2);
    default:
        return nullptr;
    }
}
