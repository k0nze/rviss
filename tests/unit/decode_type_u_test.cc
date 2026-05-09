#include <catch2/catch_test_macros.hpp>

#include "rviss/core/decoder.h"
#include "rviss/rviss.h"

namespace {

uint32_t encode_u_type(uint32_t opcode, Register rd, uint32_t imm) {
    return ((imm & 0x000fffffU) << 12U)
        | ((static_cast<uint32_t>(rd) & 0x1fU) << 7U)
        | (opcode & 0x7fU);
}

}

TEST_CASE("Decoder decodes LUI instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_u_type(0x37U, Register::a0, 0xabcdeU));

    REQUIRE(instruction != nullptr);
    const auto* upper = dynamic_cast<const LUI*>(instruction.get());
    REQUIRE(upper != nullptr);
    REQUIRE(upper->opcode == Opcode::LUI);
    REQUIRE(upper->rd == Register::a0);
    REQUIRE(upper->imm == 0xabcdeU);
}

TEST_CASE("Decoder decodes AUIPC instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_u_type(0x17U, Register::a1, 0x54321U));

    REQUIRE(instruction != nullptr);
    const auto* upper = dynamic_cast<const AUIPC*>(instruction.get());
    REQUIRE(upper != nullptr);
    REQUIRE(upper->opcode == Opcode::AUIPC);
    REQUIRE(upper->rd == Register::a1);
    REQUIRE(upper->imm == 0x54321U);
}

TEST_CASE("Decoder decodes zero U-type immediates") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_u_type(0x37U, Register::zero, 0x00000U));

    REQUIRE(instruction != nullptr);
    const auto* upper = dynamic_cast<const LUI*>(instruction.get());
    REQUIRE(upper != nullptr);
    REQUIRE(upper->imm == 0x00000U);
}

TEST_CASE("Decoder decodes maximum U-type immediates") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_u_type(0x17U, Register::t6, 0xfffffU));

    REQUIRE(instruction != nullptr);
    const auto* upper = dynamic_cast<const AUIPC*>(instruction.get());
    REQUIRE(upper != nullptr);
    REQUIRE(upper->imm == 0xfffffU);
}

TEST_CASE("Decoder does not decode compressed words as U-type instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(0x00002000U);

    REQUIRE(instruction == nullptr);
}

TEST_CASE("Decoder only decodes the first compressed instruction from a 32-bit word before standard U-type dispatch") {
    Decoder decoder;
    const uint32_t first = 0x0001U;
    const uint32_t second = encode_u_type(0x37U, Register::a2, 0x12345U);
    const auto instruction = decoder.decode(first | (second << 16U));

    REQUIRE(instruction != nullptr);
    const auto* compressed = dynamic_cast<const C_NOP*>(instruction.get());
    REQUIRE(compressed != nullptr);
}
