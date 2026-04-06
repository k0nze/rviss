#include "rviss/core/decoder.h"

#include "decoder_internal.h"

std::unique_ptr<Instruction> Decoder::decode(uint32_t encoded_instruction) const {
    if ((encoded_instruction & 0b11U) != 0b11U) {
        const uint16_t compressed_instruction = static_cast<uint16_t>(encoded_instruction & 0xffffU);

        if ((compressed_instruction & 0x3U) == 0b01U
            && ((compressed_instruction >> 13U) & 0x7U) == 0b100U
            && ((compressed_instruction >> 10U) & 0x3U) == 0b11U) {
            return decode_type_ca(compressed_instruction);
        }

        return nullptr;
    }

    switch (encoded_instruction & 0x7fU) {
    case 0x63U:
        return decode_type_b(encoded_instruction);
    case 0x2fU:
        return decode_type_amo(encoded_instruction);
    default:
        return nullptr;
    }
}
