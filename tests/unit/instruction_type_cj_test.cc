#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

TEST_CASE("C_J stores opcode and operand") {
    C_J instruction(42);

    REQUIRE(instruction.opcode == Opcode::C_J);
    REQUIRE(instruction.imm == 42);
}
