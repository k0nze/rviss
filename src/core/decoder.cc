#include "rviss/core/decoder.h"

#include "decoder_internal.h"

std::unique_ptr<Instruction> Decoder::decode(uint32_t encoded_instruction) const {
    if ((encoded_instruction & 0b11U) != 0b11U) {
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
