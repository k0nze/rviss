#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

TEST_CASE("LUI stores opcode and operands") {
    LUI instruction(Register::s10, 1024);

    REQUIRE(instruction.opcode == Opcode::LUI);
    REQUIRE(instruction.rd == Register::s10);
    REQUIRE(instruction.imm == 1024);
}

TEST_CASE("AUIPC stores opcode and operands") {
    AUIPC instruction(Register::s11, 4096);

    REQUIRE(instruction.opcode == Opcode::AUIPC);
    REQUIRE(instruction.rd == Register::s11);
    REQUIRE(instruction.imm == 4096);
}

TEST_CASE("InstructionTypeU-derived instructions store destination and immediate") {
    LUI instruction(Register::a0, 2048);

    const InstructionTypeU& base = instruction;

    REQUIRE(base.opcode == Opcode::LUI);
    REQUIRE(base.rd == Register::a0);
    REQUIRE(base.imm == 2048);
}

TEST_CASE("U-type immediates are masked to 20 bits") {
    LUI instruction(Register::a1, 0x1abcde);

    REQUIRE(instruction.imm == 0x0abcde);
}
