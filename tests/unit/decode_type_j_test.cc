#include <catch2/catch_test_macros.hpp>

#include "rviss/core/decoder.h"
#include "rviss/rviss.h"

namespace {

uint32_t encode_j_type(Register rd, uint32_t imm) {
    return (((imm >> 20U) & 0x1U) << 31U)
        | (((imm >> 1U) & 0x03ffU) << 21U)
        | (((imm >> 11U) & 0x1U) << 20U)
        | (((imm >> 12U) & 0xffU) << 12U)
        | ((static_cast<uint32_t>(rd) & 0x1fU) << 7U)
        | 0x6fU;
}

}

TEST_CASE("Decoder decodes JAL instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_j_type(Register::ra, 0x0aaaaU));

    REQUIRE(instruction != nullptr);
    const auto* jump = dynamic_cast<const JAL*>(instruction.get());
    REQUIRE(jump != nullptr);
    REQUIRE(jump->opcode == Opcode::JAL);
    REQUIRE(jump->rd == Register::ra);
    REQUIRE(jump->imm == 0x0aaaaU);
}

TEST_CASE("Decoder decodes zero J-type immediates") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_j_type(Register::zero, 0x000000U));

    REQUIRE(instruction != nullptr);
    const auto* jump = dynamic_cast<const JAL*>(instruction.get());
    REQUIRE(jump != nullptr);
    REQUIRE(jump->rd == Register::zero);
    REQUIRE(jump->imm == 0x000000U);
}

TEST_CASE("Decoder decodes maximum J-type immediates") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_j_type(Register::t6, 0x1ffffeU));

    REQUIRE(instruction != nullptr);
    const auto* jump = dynamic_cast<const JAL*>(instruction.get());
    REQUIRE(jump != nullptr);
    REQUIRE(jump->rd == Register::t6);
    REQUIRE(jump->imm == 0x1ffffeU);
}

TEST_CASE("Decoder preserves sign-bit-set J-type immediates as encoded bits") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_j_type(Register::a0, 0x100000U));

    REQUIRE(instruction != nullptr);
    const auto* jump = dynamic_cast<const JAL*>(instruction.get());
    REQUIRE(jump != nullptr);
    REQUIRE(jump->imm == 0x100000U);
}

TEST_CASE("Decoder only decodes the first compressed instruction from a 32-bit word before standard J-type dispatch") {
    Decoder decoder;
    const uint32_t first = 0x0001U;
    const uint32_t second = encode_j_type(Register::a1, 0x000800U);
    const auto instruction = decoder.decode(first | (second << 16U));

    REQUIRE(instruction != nullptr);
    const auto* compressed = dynamic_cast<const C_NOP*>(instruction.get());
    REQUIRE(compressed != nullptr);
}
