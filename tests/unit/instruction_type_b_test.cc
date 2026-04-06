#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

namespace {

class TestInstructionTypeB final: public InstructionTypeB {
public:
    TestInstructionTypeB(Register rs1, Register rs2, uint16_t imm)
        : InstructionTypeB(Opcode::ECALL, rs1, rs2, imm) {}
};

}

TEST_CASE("InstructionTypeB-derived instructions store opcode and operands") {
    TestInstructionTypeB instruction(Register::a0, Register::a1, 0x1234);

    const InstructionTypeB& base = instruction;

    REQUIRE(base.opcode == Opcode::ECALL);
    REQUIRE(base.rs1 == Register::a0);
    REQUIRE(base.rs2 == Register::a1);
    REQUIRE(base.imm == 0x1234);
}

TEST_CASE("B-type immediates are masked to 13 bits") {
    TestInstructionTypeB instruction(Register::a2, Register::a3, 0x3abc);

    REQUIRE(instruction.imm == 0x1abc);
}
