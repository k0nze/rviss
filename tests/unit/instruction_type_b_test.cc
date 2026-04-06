#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

TEST_CASE("B-type immediates are masked to 13 bits") {
    BEQ instruction(Register::a2, Register::a3, 0x3abc);

    REQUIRE(instruction.imm == 0x1abc);
}

TEST_CASE("BEQ stores opcode and operands") {
    BEQ instruction(Register::a4, Register::a5, 0x120);

    REQUIRE(instruction.opcode == Opcode::BEQ);
    REQUIRE(instruction.rs1 == Register::a4);
    REQUIRE(instruction.rs2 == Register::a5);
    REQUIRE(instruction.imm == 0x120);
}

TEST_CASE("BNE stores opcode and operands") {
    BNE instruction(Register::a6, Register::a7, 0x240);

    REQUIRE(instruction.opcode == Opcode::BNE);
    REQUIRE(instruction.rs1 == Register::a6);
    REQUIRE(instruction.rs2 == Register::a7);
    REQUIRE(instruction.imm == 0x240);
}

TEST_CASE("BLT stores opcode and operands") {
    BLT instruction(Register::s0, Register::s1, 0x360);

    REQUIRE(instruction.opcode == Opcode::BLT);
    REQUIRE(instruction.rs1 == Register::s0);
    REQUIRE(instruction.rs2 == Register::s1);
    REQUIRE(instruction.imm == 0x360);
}

TEST_CASE("BGE stores opcode and operands") {
    BGE instruction(Register::s2, Register::s3, 0x480);

    REQUIRE(instruction.opcode == Opcode::BGE);
    REQUIRE(instruction.rs1 == Register::s2);
    REQUIRE(instruction.rs2 == Register::s3);
    REQUIRE(instruction.imm == 0x480);
}

TEST_CASE("BLTU stores opcode and operands") {
    BLTU instruction(Register::s4, Register::s5, 0x5a0);

    REQUIRE(instruction.opcode == Opcode::BLTU);
    REQUIRE(instruction.rs1 == Register::s4);
    REQUIRE(instruction.rs2 == Register::s5);
    REQUIRE(instruction.imm == 0x5a0);
}

TEST_CASE("BGEU stores opcode and operands") {
    BGEU instruction(Register::s6, Register::s7, 0x6c0);

    REQUIRE(instruction.opcode == Opcode::BGEU);
    REQUIRE(instruction.rs1 == Register::s6);
    REQUIRE(instruction.rs2 == Register::s7);
    REQUIRE(instruction.imm == 0x6c0);
}
