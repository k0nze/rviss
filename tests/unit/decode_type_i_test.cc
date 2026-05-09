#include <catch2/catch_test_macros.hpp>

#include "rviss/core/decoder.h"
#include "rviss/rviss.h"

namespace {

uint32_t encode_i_type(uint32_t opcode, uint32_t funct3, Register rd, Register rs1, uint16_t imm) {
    return ((static_cast<uint32_t>(imm & 0x0fffU)) << 20U)
        | ((static_cast<uint32_t>(rs1) & 0x1fU) << 15U)
        | ((funct3 & 0x7U) << 12U)
        | ((static_cast<uint32_t>(rd) & 0x1fU) << 7U)
        | (opcode & 0x7fU);
}

uint32_t encode_sfence_vma(Register rs1, Register rs2) {
    return (0b0001001U << 25U)
        | ((static_cast<uint32_t>(rs2) & 0x1fU) << 20U)
        | ((static_cast<uint32_t>(rs1) & 0x1fU) << 15U)
        | 0x73U;
}

}

TEST_CASE("Decoder decodes ADDI instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x13U, 0b000U, Register::a0, Register::a1, 0x123U));
    REQUIRE(dynamic_cast<const ADDI*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes SLTI instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x13U, 0b010U, Register::a2, Register::a3, 0x234U));
    REQUIRE(dynamic_cast<const SLTI*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes SLTIU instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x13U, 0b011U, Register::a4, Register::a5, 0x345U));
    REQUIRE(dynamic_cast<const SLTIU*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes XORI instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x13U, 0b100U, Register::a6, Register::a7, 0x456U));
    REQUIRE(dynamic_cast<const XORI*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes ORI instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x13U, 0b110U, Register::s0, Register::s1, 0x567U));
    REQUIRE(dynamic_cast<const ORI*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes ANDI instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x13U, 0b111U, Register::s2, Register::s3, 0x678U));
    REQUIRE(dynamic_cast<const ANDI*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes SLLI instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x13U, 0b001U, Register::s4, Register::s5, 0x005U));
    REQUIRE(dynamic_cast<const SLLI*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes SRLI instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x13U, 0b101U, Register::s6, Register::s7, 0x006U));
    REQUIRE(dynamic_cast<const SRLI*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes SRAI instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x13U, 0b101U, Register::s8, Register::s9, 0x406U));
    REQUIRE(dynamic_cast<const SRAI*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes LB instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x03U, 0b000U, Register::s10, Register::s11, 0x080U));
    REQUIRE(dynamic_cast<const LB*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes LH instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x03U, 0b001U, Register::t0, Register::t1, 0x100U));
    REQUIRE(dynamic_cast<const LH*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes LW instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x03U, 0b010U, Register::t2, Register::t3, 0x200U));
    REQUIRE(dynamic_cast<const LW*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes LD instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x03U, 0b011U, Register::t4, Register::t5, 0x300U));
    REQUIRE(dynamic_cast<const LD*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes LBU instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x03U, 0b100U, Register::a0, Register::a1, 0x040U));
    REQUIRE(dynamic_cast<const LBU*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes LHU instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x03U, 0b101U, Register::a2, Register::a3, 0x060U));
    REQUIRE(dynamic_cast<const LHU*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes LWU instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x03U, 0b110U, Register::a4, Register::a5, 0x0a0U));
    REQUIRE(dynamic_cast<const LWU*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes JALR instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x67U, 0b000U, Register::a6, Register::a7, 0x0ccU));
    REQUIRE(dynamic_cast<const JALR*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes ECALL instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(0x00000073U);
    REQUIRE(dynamic_cast<const ECALL*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes EBREAK instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(0x00100073U);
    REQUIRE(dynamic_cast<const EBREAK*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes FENCE instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x0fU, 0b000U, Register::t0, Register::t1, 0x123U));
    const auto* decoded = dynamic_cast<const FENCE*>(instruction.get());
    REQUIRE(decoded != nullptr);
    REQUIRE(decoded->imm == 0x123U);
}

TEST_CASE("Decoder decodes FENCE_I instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x0fU, 0b001U, Register::t2, Register::t3, 0x345U));
    const auto* decoded = dynamic_cast<const FENCE_I*>(instruction.get());
    REQUIRE(decoded != nullptr);
    REQUIRE(decoded->rd == Register::zero);
    REQUIRE(decoded->rs1 == Register::zero);
    REQUIRE(decoded->imm == 0);
}

TEST_CASE("Decoder decodes URET instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(0x00200073U);
    REQUIRE(dynamic_cast<const URET*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes SRET instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(0x10200073U);
    REQUIRE(dynamic_cast<const SRET*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes MRET instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(0x30200073U);
    REQUIRE(dynamic_cast<const MRET*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes WFI instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(0x10500073U);
    REQUIRE(dynamic_cast<const WFI*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes CSRRW instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x73U, 0b001U, Register::a0, Register::a1, 0xc00U));
    REQUIRE(dynamic_cast<const CSRRW*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes CSRRS instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x73U, 0b010U, Register::a2, Register::a3, 0xc01U));
    REQUIRE(dynamic_cast<const CSRRS*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes CSRRC instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x73U, 0b011U, Register::a4, Register::a5, 0xc02U));
    REQUIRE(dynamic_cast<const CSRRC*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes CSRRWI instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x73U, 0b101U, Register::a6, Register::a7, 0xc03U));
    REQUIRE(dynamic_cast<const CSRRWI*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes CSRRSI instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x73U, 0b110U, Register::s0, Register::s1, 0xc04U));
    REQUIRE(dynamic_cast<const CSRRSI*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes CSRRCI instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x73U, 0b111U, Register::s2, Register::s3, 0xc05U));
    REQUIRE(dynamic_cast<const CSRRCI*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes SFENCE_VMA instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_sfence_vma(Register::t0, Register::t1));
    const auto* decoded = dynamic_cast<const SFENCE_VMA*>(instruction.get());
    REQUIRE(decoded != nullptr);
    REQUIRE(decoded->rs1 == Register::t0);
    REQUIRE(decoded->rs2 == Register::t1);
}

TEST_CASE("Decoder decodes ADDIW instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x1bU, 0b000U, Register::s4, Register::s5, 0x0eaU));
    REQUIRE(dynamic_cast<const ADDIW*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes SLLIW instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x1bU, 0b001U, Register::s6, Register::s7, 0x00cU));
    REQUIRE(dynamic_cast<const SLLIW*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes SRLIW instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x1bU, 0b101U, Register::s8, Register::s9, 0x00dU));
    REQUIRE(dynamic_cast<const SRLIW*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder decodes SRAIW instructions") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x1bU, 0b101U, Register::s10, Register::s11, 0x40eU));
    REQUIRE(dynamic_cast<const SRAIW*>(instruction.get()) != nullptr);
}

TEST_CASE("Decoder preserves sign-bit-set I-type immediates as encoded bits") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x13U, 0b000U, Register::a0, Register::a1, 0x800U));
    const auto* decoded = dynamic_cast<const ADDI*>(instruction.get());
    REQUIRE(decoded != nullptr);
    REQUIRE(decoded->imm == 0x800U);
}

TEST_CASE("Decoder returns nullptr for invalid OP-IMM shift encodings") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x13U, 0b001U, Register::a0, Register::a1, 0x800U));
    REQUIRE(instruction == nullptr);
}

TEST_CASE("Decoder returns nullptr for invalid OP-IMM-32 shift encodings") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x1bU, 0b101U, Register::a0, Register::a1, 0x200U));
    REQUIRE(instruction == nullptr);
}

TEST_CASE("Decoder returns nullptr for invalid load funct3") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x03U, 0b111U, Register::a0, Register::a1, 0x010U));
    REQUIRE(instruction == nullptr);
}

TEST_CASE("Decoder returns nullptr for invalid JALR funct3") {
    Decoder decoder;
    const auto instruction = decoder.decode(encode_i_type(0x67U, 0b001U, Register::a0, Register::a1, 0x010U));
    REQUIRE(instruction == nullptr);
}

TEST_CASE("Decoder only decodes the first compressed instruction from a 32-bit word before standard I-type dispatch") {
    Decoder decoder;
    const uint32_t first = 0x0001U;
    const uint32_t second = encode_i_type(0x13U, 0b000U, Register::a0, Register::a1, 0x123U);
    const auto instruction = decoder.decode(first | (second << 16U));
    REQUIRE(dynamic_cast<const C_NOP*>(instruction.get()) != nullptr);
}

