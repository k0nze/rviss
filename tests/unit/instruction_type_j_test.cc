#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

TEST_CASE("JAL stores opcode and operands") {
    JAL instruction(Register::ra, 2048);

    REQUIRE(instruction.opcode == Opcode::JAL);
    REQUIRE(instruction.rd == Register::ra);
    REQUIRE(instruction.imm == 2048);
}

TEST_CASE("J-type immediates are masked to 21 bits") {
    JAL instruction(Register::a0, 0x003fffffU);

    REQUIRE(instruction.imm == 0x001fffffU);
}
