#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

TEST_CASE("C_LW stores opcode and operands") {
    C_LW instruction(Register::a0, Register::a1, 12);

    REQUIRE(instruction.opcode == Opcode::C_LW);
    REQUIRE(instruction.rd == Register::a0);
    REQUIRE(instruction.rs1 == Register::a1);
    REQUIRE(instruction.imm == 12);
}

TEST_CASE("C_LD stores opcode and operands") {
    C_LD instruction(Register::a2, Register::a3, 16);

    REQUIRE(instruction.opcode == Opcode::C_LD);
    REQUIRE(instruction.rd == Register::a2);
    REQUIRE(instruction.rs1 == Register::a3);
    REQUIRE(instruction.imm == 16);
}
