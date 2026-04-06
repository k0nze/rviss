#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

TEST_CASE("C_SWSP stores opcode and operands") {
    C_SWSP instruction(Register::a0, 12);

    REQUIRE(instruction.opcode == Opcode::C_SWSP);
    REQUIRE(instruction.rs2 == Register::a0);
    REQUIRE(instruction.imm == 12);
}

TEST_CASE("C_SDSP stores opcode and operands") {
    C_SDSP instruction(Register::a1, 16);

    REQUIRE(instruction.opcode == Opcode::C_SDSP);
    REQUIRE(instruction.rs2 == Register::a1);
    REQUIRE(instruction.imm == 16);
}
