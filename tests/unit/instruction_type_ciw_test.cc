#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

TEST_CASE("C_ADDI4SPN stores opcode and operands") {
    C_ADDI4SPN instruction(Register::a0, 32);

    REQUIRE(instruction.opcode == Opcode::C_ADDI4SPN);
    REQUIRE(instruction.rd == Register::a0);
    REQUIRE(instruction.imm == 32);
}
