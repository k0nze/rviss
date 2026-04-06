#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

TEST_CASE("C_SRLI stores opcode and operands") {
    C_SRLI instruction(Register::s0, 3);

    REQUIRE(instruction.opcode == Opcode::C_SRLI);
    REQUIRE(instruction.rs1 == Register::s0);
    REQUIRE(instruction.imm == 3);
}

TEST_CASE("C_SRAI stores opcode and operands") {
    C_SRAI instruction(Register::s1, 4);

    REQUIRE(instruction.opcode == Opcode::C_SRAI);
    REQUIRE(instruction.rs1 == Register::s1);
    REQUIRE(instruction.imm == 4);
}

TEST_CASE("C_ANDI stores opcode and operands") {
    C_ANDI instruction(Register::s2, 5);

    REQUIRE(instruction.opcode == Opcode::C_ANDI);
    REQUIRE(instruction.rs1 == Register::s2);
    REQUIRE(instruction.imm == 5);
}

TEST_CASE("C_BEQZ stores opcode and operands") {
    C_BEQZ instruction(Register::s3, 6);

    REQUIRE(instruction.opcode == Opcode::C_BEQZ);
    REQUIRE(instruction.rs1 == Register::s3);
    REQUIRE(instruction.imm == 6);
}

TEST_CASE("C_BNEZ stores opcode and operands") {
    C_BNEZ instruction(Register::s4, 7);

    REQUIRE(instruction.opcode == Opcode::C_BNEZ);
    REQUIRE(instruction.rs1 == Register::s4);
    REQUIRE(instruction.imm == 7);
}
