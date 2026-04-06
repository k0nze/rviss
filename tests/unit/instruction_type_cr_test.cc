#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

TEST_CASE("C_JR stores opcode and operands") {
    C_JR instruction(Register::ra);

    REQUIRE(instruction.opcode == Opcode::C_JR);
    REQUIRE(instruction.rd_rs1 == Register::ra);
    REQUIRE(instruction.rs2 == Register::zero);
}

TEST_CASE("C_MV stores opcode and operands") {
    C_MV instruction(Register::a0, Register::a1);

    REQUIRE(instruction.opcode == Opcode::C_MV);
    REQUIRE(instruction.rd_rs1 == Register::a0);
    REQUIRE(instruction.rs2 == Register::a1);
}

TEST_CASE("C_EBREAK stores opcode and fixed fields") {
    C_EBREAK instruction;

    REQUIRE(instruction.opcode == Opcode::C_EBREAK);
    REQUIRE(instruction.rd_rs1 == Register::zero);
    REQUIRE(instruction.rs2 == Register::zero);
}

TEST_CASE("C_JALR stores opcode and operands") {
    C_JALR instruction(Register::s0);

    REQUIRE(instruction.opcode == Opcode::C_JALR);
    REQUIRE(instruction.rd_rs1 == Register::s0);
    REQUIRE(instruction.rs2 == Register::zero);
}

TEST_CASE("C_ADD stores opcode and operands") {
    C_ADD instruction(Register::s1, Register::s2);

    REQUIRE(instruction.opcode == Opcode::C_ADD);
    REQUIRE(instruction.rd_rs1 == Register::s1);
    REQUIRE(instruction.rs2 == Register::s2);
}
