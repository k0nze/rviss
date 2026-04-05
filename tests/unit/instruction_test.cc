#include <catch2/catch_test_macros.hpp>

#include "rvsim/rvsim.h"

TEST_CASE("ADDI stores opcode and operands") {
    ADDI instruction(Register::a0, Register::a1, 123);

    REQUIRE(instruction.opcode == Opcode::ADDI);
    REQUIRE(instruction.rd == Register::a0);
    REQUIRE(instruction.rs1 == Register::a1);
    REQUIRE(instruction.imm == 123);
}

TEST_CASE("SLTI stores opcode and operands") {
    SLTI instruction(Register::a2, Register::a3, 456);

    REQUIRE(instruction.opcode == Opcode::SLTI);
    REQUIRE(instruction.rd == Register::a2);
    REQUIRE(instruction.rs1 == Register::a3);
    REQUIRE(instruction.imm == 456);
}

TEST_CASE("SLTIU stores opcode and operands") {
    SLTIU instruction(Register::a4, Register::a5, 789);

    REQUIRE(instruction.opcode == Opcode::SLTIU);
    REQUIRE(instruction.rd == Register::a4);
    REQUIRE(instruction.rs1 == Register::a5);
    REQUIRE(instruction.imm == 789);
}

TEST_CASE("ANDI stores opcode and operands") {
    ANDI instruction(Register::a6, Register::a7, 321);

    REQUIRE(instruction.opcode == Opcode::ANDI);
    REQUIRE(instruction.rd == Register::a6);
    REQUIRE(instruction.rs1 == Register::a7);
    REQUIRE(instruction.imm == 321);
}

TEST_CASE("ORI stores opcode and operands") {
    ORI instruction(Register::s0, Register::s1, 654);

    REQUIRE(instruction.opcode == Opcode::ORI);
    REQUIRE(instruction.rd == Register::s0);
    REQUIRE(instruction.rs1 == Register::s1);
    REQUIRE(instruction.imm == 654);
}

TEST_CASE("XORI stores opcode and operands") {
    XORI instruction(Register::s2, Register::s3, 987);

    REQUIRE(instruction.opcode == Opcode::XORI);
    REQUIRE(instruction.rd == Register::s2);
    REQUIRE(instruction.rs1 == Register::s3);
    REQUIRE(instruction.imm == 987);
}

TEST_CASE("SLLI stores opcode and operands") {
    SLLI instruction(Register::s4, Register::s5, 5);

    REQUIRE(instruction.opcode == Opcode::SLLI);
    REQUIRE(instruction.rd == Register::s4);
    REQUIRE(instruction.rs1 == Register::s5);
    REQUIRE(instruction.imm == 5);
}
