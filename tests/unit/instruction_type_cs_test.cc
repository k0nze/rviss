#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

TEST_CASE("C_SW stores opcode and operands") {
    C_SW instruction(Register::a0, Register::a1, 12);

    REQUIRE(instruction.opcode == Opcode::C_SW);
    REQUIRE(instruction.rs1 == Register::a0);
    REQUIRE(instruction.rs2 == Register::a1);
    REQUIRE(instruction.imm == 12);
}

TEST_CASE("C_SD stores opcode and operands") {
    C_SD instruction(Register::a2, Register::a3, 16);

    REQUIRE(instruction.opcode == Opcode::C_SD);
    REQUIRE(instruction.rs1 == Register::a2);
    REQUIRE(instruction.rs2 == Register::a3);
    REQUIRE(instruction.imm == 16);
}
