#include <catch2/catch_test_macros.hpp>

#include "rvsim/rvsim.h"

TEST_CASE("Instruction stores opcode") {
    Instruction instruction(Opcode::ADD);

    REQUIRE(instruction.opcode == Opcode::ADD);
}
