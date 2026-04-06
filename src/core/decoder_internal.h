#ifndef RVISS_CORE_DECODER_INTERNAL_H
#define RVISS_CORE_DECODER_INTERNAL_H

#include "rviss/isa/instruction.h"
#include <cstdint>
#include <memory>

std::unique_ptr<Instruction> decode_type_r(uint32_t encoded_instruction);
std::unique_ptr<Instruction> decode_type_i(uint32_t encoded_instruction);
std::unique_ptr<Instruction> decode_type_s(uint32_t encoded_instruction);
std::unique_ptr<Instruction> decode_type_b(uint32_t encoded_instruction);
std::unique_ptr<Instruction> decode_type_u(uint32_t encoded_instruction);
std::unique_ptr<Instruction> decode_type_j(uint32_t encoded_instruction);
std::unique_ptr<Instruction> decode_type_amo(uint32_t encoded_instruction);

std::unique_ptr<Instruction> decode_type_cr(uint16_t encoded_instruction);
std::unique_ptr<Instruction> decode_type_ci(uint16_t encoded_instruction);
std::unique_ptr<Instruction> decode_type_ciw(uint16_t encoded_instruction);
std::unique_ptr<Instruction> decode_type_cl(uint16_t encoded_instruction);
std::unique_ptr<Instruction> decode_type_cs(uint16_t encoded_instruction);
std::unique_ptr<Instruction> decode_type_css(uint16_t encoded_instruction);
std::unique_ptr<Instruction> decode_type_ca(uint16_t encoded_instruction);
std::unique_ptr<Instruction> decode_type_cb(uint16_t encoded_instruction);
std::unique_ptr<Instruction> decode_type_cj(uint16_t encoded_instruction);

#endif
