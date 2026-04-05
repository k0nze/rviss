#include <catch2/catch_test_macros.hpp>

#include "rvsim/rvsim.h"

TEST_CASE("ADDI stores opcode and operands") {
    ADDI instruction(Register::a0, Register::a1, 123);

    REQUIRE(instruction.opcode == Opcode::ADDI);
    REQUIRE(instruction.rd == Register::a0);
    REQUIRE(instruction.rs1 == Register::a1);
    REQUIRE(instruction.imm == 123);
}
