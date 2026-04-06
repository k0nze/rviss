#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

TEST_CASE("C_NOP stores opcode and fixed fields") {
    C_NOP instruction;

    REQUIRE(instruction.opcode == Opcode::C_NOP);
    REQUIRE(instruction.rd_rs1 == Register::zero);
    REQUIRE(instruction.imm == 0);
}

TEST_CASE("C_ADDI stores opcode and operands") {
    C_ADDI instruction(Register::a0, 7);

    REQUIRE(instruction.opcode == Opcode::C_ADDI);
    REQUIRE(instruction.rd_rs1 == Register::a0);
    REQUIRE(instruction.imm == 7);
}

TEST_CASE("C_LI stores opcode and operands") {
    C_LI instruction(Register::a1, 9);

    REQUIRE(instruction.opcode == Opcode::C_LI);
    REQUIRE(instruction.rd_rs1 == Register::a1);
    REQUIRE(instruction.imm == 9);
}

TEST_CASE("C_LUI stores opcode and operands") {
    C_LUI instruction(Register::a2, 11);

    REQUIRE(instruction.opcode == Opcode::C_LUI);
    REQUIRE(instruction.rd_rs1 == Register::a2);
    REQUIRE(instruction.imm == 11);
}

TEST_CASE("C_ADDI16SP stores opcode and operands") {
    C_ADDI16SP instruction(13);

    REQUIRE(instruction.opcode == Opcode::C_ADDI16SP);
    REQUIRE(instruction.rd_rs1 == Register::sp);
    REQUIRE(instruction.imm == 13);
}

TEST_CASE("C_SLLI stores opcode and operands") {
    C_SLLI instruction(Register::a3, 3);

    REQUIRE(instruction.opcode == Opcode::C_SLLI);
    REQUIRE(instruction.rd_rs1 == Register::a3);
    REQUIRE(instruction.imm == 3);
}

TEST_CASE("C_LWSP stores opcode and operands") {
    C_LWSP instruction(Register::a4, 20);

    REQUIRE(instruction.opcode == Opcode::C_LWSP);
    REQUIRE(instruction.rd_rs1 == Register::a4);
    REQUIRE(instruction.imm == 20);
}

TEST_CASE("C_ADDIW stores opcode and operands") {
    C_ADDIW instruction(Register::a5, 15);

    REQUIRE(instruction.opcode == Opcode::C_ADDIW);
    REQUIRE(instruction.rd_rs1 == Register::a5);
    REQUIRE(instruction.imm == 15);
}

TEST_CASE("C_LDSP stores opcode and operands") {
    C_LDSP instruction(Register::a6, 24);

    REQUIRE(instruction.opcode == Opcode::C_LDSP);
    REQUIRE(instruction.rd_rs1 == Register::a6);
    REQUIRE(instruction.imm == 24);
}
