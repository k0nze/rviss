#include "decoder_internal.h"

#include "rviss/isa/jal.h"
#include "rviss/isa/register.h"

namespace {

Register decode_register(uint32_t bits) {
    return static_cast<Register>(bits & 0x1fU);
}

uint32_t decode_j_immediate(uint32_t encoded_instruction) {
    const uint32_t bits10_1 = ((encoded_instruction >> 21U) & 0x03ffU) << 1U;
    const uint32_t bit11 = ((encoded_instruction >> 20U) & 0x1U) << 11U;
    const uint32_t bits19_12 = ((encoded_instruction >> 12U) & 0xffU) << 12U;
    const uint32_t bit20 = ((encoded_instruction >> 31U) & 0x1U) << 20U;

    return bit20 | bits19_12 | bit11 | bits10_1;
}

}

std::unique_ptr<Instruction> decode_type_j(uint32_t encoded_instruction) {
    const Register rd = decode_register(encoded_instruction >> 7U);
    const uint32_t imm = decode_j_immediate(encoded_instruction);

    return std::make_unique<JAL>(rd, imm);
}
