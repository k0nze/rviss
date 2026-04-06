#include "decoder_internal.h"

#include "rviss/isa/amoadd_d.h"
#include "rviss/isa/amoadd_w.h"
#include "rviss/isa/amoand_d.h"
#include "rviss/isa/amoand_w.h"
#include "rviss/isa/amomax_d.h"
#include "rviss/isa/amomax_w.h"
#include "rviss/isa/amomaxu_d.h"
#include "rviss/isa/amomaxu_w.h"
#include "rviss/isa/amomin_d.h"
#include "rviss/isa/amomin_w.h"
#include "rviss/isa/amominu_d.h"
#include "rviss/isa/amominu_w.h"
#include "rviss/isa/amoor_d.h"
#include "rviss/isa/amoor_w.h"
#include "rviss/isa/amoswap_d.h"
#include "rviss/isa/amoswap_w.h"
#include "rviss/isa/amoxor_d.h"
#include "rviss/isa/amoxor_w.h"
#include "rviss/isa/lr_d.h"
#include "rviss/isa/lr_w.h"
#include "rviss/isa/register.h"
#include "rviss/isa/sc_d.h"
#include "rviss/isa/sc_w.h"

namespace {

Register decode_register(uint32_t bits) {
    return static_cast<Register>(bits & 0x1fU);
}

template <typename WType, typename DType>
std::unique_ptr<Instruction> decode_word_or_doubleword(uint32_t funct3, Register rd, Register rs1, Register rs2) {
    switch (funct3) {
    case 0b010U:
        return std::make_unique<WType>(rd, rs1, rs2);
    case 0b011U:
        return std::make_unique<DType>(rd, rs1, rs2);
    default:
        return nullptr;
    }
}

}

std::unique_ptr<Instruction> decode_type_amo(uint32_t encoded_instruction) {
    const Register rd = decode_register(encoded_instruction >> 7U);
    const uint32_t funct3 = (encoded_instruction >> 12U) & 0x7U;
    const Register rs1 = decode_register(encoded_instruction >> 15U);
    const Register rs2 = decode_register(encoded_instruction >> 20U);
    const uint32_t funct5 = (encoded_instruction >> 27U) & 0x1fU;

    switch (funct5) {
    case 0b00010U:
        switch (funct3) {
        case 0b010U:
            return std::make_unique<LR_W>(rd, rs1);
        case 0b011U:
            return std::make_unique<LR_D>(rd, rs1);
        default:
            return nullptr;
        }
    case 0b00011U:
        return decode_word_or_doubleword<SC_W, SC_D>(funct3, rd, rs1, rs2);
    case 0b00001U:
        return decode_word_or_doubleword<AMOSWAP_W, AMOSWAP_D>(funct3, rd, rs1, rs2);
    case 0b00000U:
        return decode_word_or_doubleword<AMOADD_W, AMOADD_D>(funct3, rd, rs1, rs2);
    case 0b00100U:
        return decode_word_or_doubleword<AMOXOR_W, AMOXOR_D>(funct3, rd, rs1, rs2);
    case 0b01100U:
        return decode_word_or_doubleword<AMOAND_W, AMOAND_D>(funct3, rd, rs1, rs2);
    case 0b01000U:
        return decode_word_or_doubleword<AMOOR_W, AMOOR_D>(funct3, rd, rs1, rs2);
    case 0b10000U:
        return decode_word_or_doubleword<AMOMIN_W, AMOMIN_D>(funct3, rd, rs1, rs2);
    case 0b10100U:
        return decode_word_or_doubleword<AMOMAX_W, AMOMAX_D>(funct3, rd, rs1, rs2);
    case 0b11000U:
        return decode_word_or_doubleword<AMOMINU_W, AMOMINU_D>(funct3, rd, rs1, rs2);
    case 0b11100U:
        return decode_word_or_doubleword<AMOMAXU_W, AMOMAXU_D>(funct3, rd, rs1, rs2);
    default:
        return nullptr;
    }

}
