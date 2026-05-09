#include <catch2/catch_test_macros.hpp>

#include "rviss/core/decoder.h"
#include "rviss/rviss.h"

namespace {

uint32_t encode_s_type(uint32_t funct3, Register rs1, Register rs2, uint16_t imm) {
    return (((imm >> 5U) & 0x7fU) << 25U)
        | ((static_cast<uint32_t>(rs2) & 0x1fU) << 20U)
        | ((static_cast<uint32_t>(rs1) & 0x1fU) << 15U)
        | ((funct3 & 0x7U) << 12U)
        | ((imm & 0x1fU) << 7U)
        | 0x23U;
}

}

TEST_CASE("Decoder decodes SB instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_s_type(0b000U, Register::a0, Register::a1, 0x123U));

    REQUIRE(instruction != nullptr);
    const auto* store = dynamic_cast<const SB*>(instruction.get());
    REQUIRE(store != nullptr);
    REQUIRE(store->opcode == Opcode::SB);
    REQUIRE(store->rs1 == Register::a0);
    REQUIRE(store->rs2 == Register::a1);
    REQUIRE(store->imm == 0x123U);
}

TEST_CASE("Decoder decodes SH instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_s_type(0b001U, Register::a2, Register::a3, 0x234U));

    REQUIRE(instruction != nullptr);
    const auto* store = dynamic_cast<const SH*>(instruction.get());
    REQUIRE(store != nullptr);
    REQUIRE(store->opcode == Opcode::SH);
    REQUIRE(store->rs1 == Register::a2);
    REQUIRE(store->rs2 == Register::a3);
    REQUIRE(store->imm == 0x234U);
}

TEST_CASE("Decoder decodes SW instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_s_type(0b010U, Register::a4, Register::a5, 0x345U));

    REQUIRE(instruction != nullptr);
    const auto* store = dynamic_cast<const SW*>(instruction.get());
    REQUIRE(store != nullptr);
    REQUIRE(store->opcode == Opcode::SW);
    REQUIRE(store->rs1 == Register::a4);
    REQUIRE(store->rs2 == Register::a5);
    REQUIRE(store->imm == 0x345U);
}

TEST_CASE("Decoder decodes SD instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_s_type(0b011U, Register::a6, Register::a7, 0x456U));

    REQUIRE(instruction != nullptr);
    const auto* store = dynamic_cast<const SD*>(instruction.get());
    REQUIRE(store != nullptr);
    REQUIRE(store->opcode == Opcode::SD);
    REQUIRE(store->rs1 == Register::a6);
    REQUIRE(store->rs2 == Register::a7);
    REQUIRE(store->imm == 0x456U);
}

TEST_CASE("Decoder decodes zero S-type immediates") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_s_type(0b010U, Register::zero, Register::zero, 0x000U));

    REQUIRE(instruction != nullptr);
    const auto* store = dynamic_cast<const SW*>(instruction.get());
    REQUIRE(store != nullptr);
    REQUIRE(store->imm == 0x000U);
}

TEST_CASE("Decoder decodes maximum S-type immediates") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_s_type(0b011U, Register::t5, Register::t6, 0xfffU));

    REQUIRE(instruction != nullptr);
    const auto* store = dynamic_cast<const SD*>(instruction.get());
    REQUIRE(store != nullptr);
    REQUIRE(store->imm == 0xfffU);
}

TEST_CASE("Decoder preserves sign-bit-set S-type immediates as encoded bits") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_s_type(0b000U, Register::s0, Register::s1, 0x800U));

    REQUIRE(instruction != nullptr);
    const auto* store = dynamic_cast<const SB*>(instruction.get());
    REQUIRE(store != nullptr);
    REQUIRE(store->imm == 0x800U);
}

TEST_CASE("Decoder returns nullptr for invalid S-type funct3") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_s_type(0b100U, Register::a0, Register::a1, 0x100U));

    REQUIRE(instruction == nullptr);
}

TEST_CASE("Decoder does not decode compressed words as S-type instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(0x00002000U);

    REQUIRE(instruction == nullptr);
}

TEST_CASE("Decoder only decodes the first compressed instruction from a 32-bit word before standard S-type dispatch") {
    Decoder decoder;
    const uint32_t first = 0x0001U;
    const uint32_t second = encode_s_type(0b010U, Register::a0, Register::a1, 0x080U);
    const auto instruction = decoder.decode(first | (second << 16U));

    REQUIRE(instruction != nullptr);
    const auto* compressed = dynamic_cast<const C_NOP*>(instruction.get());
    REQUIRE(compressed != nullptr);
}
