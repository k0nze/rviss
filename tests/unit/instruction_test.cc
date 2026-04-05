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
