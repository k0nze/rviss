#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

TEST_CASE("C_SUB stores opcode and operands") {
    C_SUB instruction(Register::s0, Register::s1);

    REQUIRE(instruction.opcode == Opcode::C_SUB);
    REQUIRE(instruction.rd_rs1 == Register::s0);
    REQUIRE(instruction.rs2 == Register::s1);
}

TEST_CASE("C_XOR stores opcode and operands") {
    C_XOR instruction(Register::s2, Register::s3);

    REQUIRE(instruction.opcode == Opcode::C_XOR);
    REQUIRE(instruction.rd_rs1 == Register::s2);
    REQUIRE(instruction.rs2 == Register::s3);
}

TEST_CASE("C_OR stores opcode and operands") {
    C_OR instruction(Register::s4, Register::s5);

    REQUIRE(instruction.opcode == Opcode::C_OR);
    REQUIRE(instruction.rd_rs1 == Register::s4);
    REQUIRE(instruction.rs2 == Register::s5);
}

TEST_CASE("C_AND stores opcode and operands") {
    C_AND instruction(Register::s6, Register::s7);

    REQUIRE(instruction.opcode == Opcode::C_AND);
    REQUIRE(instruction.rd_rs1 == Register::s6);
    REQUIRE(instruction.rs2 == Register::s7);
}

TEST_CASE("C_SUBW stores opcode and operands") {
    C_SUBW instruction(Register::s8, Register::s9);

    REQUIRE(instruction.opcode == Opcode::C_SUBW);
    REQUIRE(instruction.rd_rs1 == Register::s8);
    REQUIRE(instruction.rs2 == Register::s9);
}

TEST_CASE("C_ADDW stores opcode and operands") {
    C_ADDW instruction(Register::s10, Register::s11);

    REQUIRE(instruction.opcode == Opcode::C_ADDW);
    REQUIRE(instruction.rd_rs1 == Register::s10);
    REQUIRE(instruction.rs2 == Register::s11);
}
