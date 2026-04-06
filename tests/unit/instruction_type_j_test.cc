#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

namespace {

class TestInstructionTypeJ final: public InstructionTypeJ {
public:
    TestInstructionTypeJ(Register rd, uint32_t imm)
        : InstructionTypeJ(Opcode::AUIPC, rd, imm) {}
};

}

TEST_CASE("InstructionTypeJ-derived instructions store opcode and operands") {
    TestInstructionTypeJ instruction(Register::a0, 0x12345);

    const InstructionTypeJ& base = instruction;

    REQUIRE(base.opcode == Opcode::AUIPC);
    REQUIRE(base.rd == Register::a0);
    REQUIRE(base.imm == 0x12345);
}

TEST_CASE("J-type immediates are masked to 21 bits") {
    TestInstructionTypeJ instruction(Register::a1, 0x3fffff);

    REQUIRE(instruction.imm == 0x1fffff);
}
