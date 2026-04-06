#include "decoder_internal.h"

#include "rviss/isa/beq.h"
#include "rviss/isa/bge.h"
#include "rviss/isa/bgeu.h"
#include "rviss/isa/blt.h"
#include "rviss/isa/bltu.h"
#include "rviss/isa/bne.h"
#include "rviss/isa/register.h"

namespace {

Register decode_register(uint32_t bits) {
    return static_cast<Register>(bits & 0x1fU);
}

uint16_t decode_b_immediate(uint32_t encoded_instruction) {
    const uint16_t bit11 = static_cast<uint16_t>(((encoded_instruction >> 7U) & 0x1U) << 11U);
    const uint16_t bits4_1 = static_cast<uint16_t>(((encoded_instruction >> 8U) & 0x0fU) << 1U);
    const uint16_t bits10_5 = static_cast<uint16_t>(((encoded_instruction >> 25U) & 0x3fU) << 5U);
    const uint16_t bit12 = static_cast<uint16_t>(((encoded_instruction >> 31U) & 0x1U) << 12U);

    return static_cast<uint16_t>(bit12 | bit11 | bits10_5 | bits4_1);
}

}

std::unique_ptr<Instruction> decode_type_b(uint32_t encoded_instruction) {
    const Register rs1 = decode_register(encoded_instruction >> 15U);
    const Register rs2 = decode_register(encoded_instruction >> 20U);
    const uint16_t imm = decode_b_immediate(encoded_instruction);

    switch ((encoded_instruction >> 12U) & 0x7U) {
    case 0b000U:
        return std::make_unique<BEQ>(rs1, rs2, imm);
    case 0b001U:
        return std::make_unique<BNE>(rs1, rs2, imm);
    case 0b100U:
        return std::make_unique<BLT>(rs1, rs2, imm);
    case 0b101U:
        return std::make_unique<BGE>(rs1, rs2, imm);
    case 0b110U:
        return std::make_unique<BLTU>(rs1, rs2, imm);
    case 0b111U:
        return std::make_unique<BGEU>(rs1, rs2, imm);
    default:
        return nullptr;
    }
}
