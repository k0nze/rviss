#ifndef RVISS_CORE_DECODER_H
#define RVISS_CORE_DECODER_H

#include "rviss/isa/instruction.h"
#include <cstdint>
#include <memory>

class Decoder {
public:
    std::unique_ptr<Instruction> decode(uint32_t encoded_instruction) const;
};

#endif
