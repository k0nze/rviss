#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

TEST_CASE("S-type immediates are masked to 12 bits") {
    SB instruction(Register::a0, Register::a1, 0x1def);

    REQUIRE(instruction.imm == 0x0def);
}

TEST_CASE("SB stores opcode and operands") {
    SB instruction(Register::a2, Register::a3, 0x120);

    REQUIRE(instruction.opcode == Opcode::SB);
    REQUIRE(instruction.rs1 == Register::a2);
    REQUIRE(instruction.rs2 == Register::a3);
    REQUIRE(instruction.imm == 0x120);
}

TEST_CASE("SH stores opcode and operands") {
    SH instruction(Register::a4, Register::a5, 0x240);

    REQUIRE(instruction.opcode == Opcode::SH);
    REQUIRE(instruction.rs1 == Register::a4);
    REQUIRE(instruction.rs2 == Register::a5);
    REQUIRE(instruction.imm == 0x240);
}

TEST_CASE("SW stores opcode and operands") {
    SW instruction(Register::a6, Register::a7, 0x360);

    REQUIRE(instruction.opcode == Opcode::SW);
    REQUIRE(instruction.rs1 == Register::a6);
    REQUIRE(instruction.rs2 == Register::a7);
    REQUIRE(instruction.imm == 0x360);
}

TEST_CASE("SD stores opcode and operands") {
    SD instruction(Register::s0, Register::s1, 0x480);

    REQUIRE(instruction.opcode == Opcode::SD);
    REQUIRE(instruction.rs1 == Register::s0);
    REQUIRE(instruction.rs2 == Register::s1);
    REQUIRE(instruction.imm == 0x480);
}
