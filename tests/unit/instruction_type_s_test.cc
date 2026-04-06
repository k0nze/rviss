#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

namespace {

class TestInstructionTypeS final: public InstructionTypeS {
public:
    TestInstructionTypeS(Register rs1, Register rs2, uint16_t imm)
        : InstructionTypeS(Opcode::EBREAK, rs1, rs2, imm) {}
};

}

TEST_CASE("InstructionTypeS-derived instructions store opcode and operands") {
    TestInstructionTypeS instruction(Register::a4, Register::a5, 0x0abc);

    const InstructionTypeS& base = instruction;

    REQUIRE(base.opcode == Opcode::EBREAK);
    REQUIRE(base.rs1 == Register::a4);
    REQUIRE(base.rs2 == Register::a5);
    REQUIRE(base.imm == 0x0abc);
}

TEST_CASE("S-type immediates are masked to 12 bits") {
    TestInstructionTypeS instruction(Register::a6, Register::a7, 0x1def);

    REQUIRE(instruction.imm == 0x0def);
}
