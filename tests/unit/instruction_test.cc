#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

TEST_CASE("ADDI stores opcode and operands") {
    ADDI instruction(Register::a0, Register::a1, 123);

    REQUIRE(instruction.opcode == Opcode::ADDI);
    REQUIRE(instruction.rd == Register::a0);
    REQUIRE(instruction.rs1 == Register::a1);
    REQUIRE(instruction.imm == 123);
}

TEST_CASE("SLTI stores opcode and operands") {
    SLTI instruction(Register::a2, Register::a3, 456);

    REQUIRE(instruction.opcode == Opcode::SLTI);
    REQUIRE(instruction.rd == Register::a2);
    REQUIRE(instruction.rs1 == Register::a3);
    REQUIRE(instruction.imm == 456);
}

TEST_CASE("SLTIU stores opcode and operands") {
    SLTIU instruction(Register::a4, Register::a5, 789);

    REQUIRE(instruction.opcode == Opcode::SLTIU);
    REQUIRE(instruction.rd == Register::a4);
    REQUIRE(instruction.rs1 == Register::a5);
    REQUIRE(instruction.imm == 789);
}

TEST_CASE("ANDI stores opcode and operands") {
    ANDI instruction(Register::a6, Register::a7, 321);

    REQUIRE(instruction.opcode == Opcode::ANDI);
    REQUIRE(instruction.rd == Register::a6);
    REQUIRE(instruction.rs1 == Register::a7);
    REQUIRE(instruction.imm == 321);
}

TEST_CASE("ORI stores opcode and operands") {
    ORI instruction(Register::s0, Register::s1, 654);

    REQUIRE(instruction.opcode == Opcode::ORI);
    REQUIRE(instruction.rd == Register::s0);
    REQUIRE(instruction.rs1 == Register::s1);
    REQUIRE(instruction.imm == 654);
}

TEST_CASE("XORI stores opcode and operands") {
    XORI instruction(Register::s2, Register::s3, 987);

    REQUIRE(instruction.opcode == Opcode::XORI);
    REQUIRE(instruction.rd == Register::s2);
    REQUIRE(instruction.rs1 == Register::s3);
    REQUIRE(instruction.imm == 987);
}

TEST_CASE("SLLI stores opcode and operands") {
    SLLI instruction(Register::s4, Register::s5, 5);

    REQUIRE(instruction.opcode == Opcode::SLLI);
    REQUIRE(instruction.rd == Register::s4);
    REQUIRE(instruction.rs1 == Register::s5);
    REQUIRE(instruction.imm == 5);
}

TEST_CASE("SRLI stores opcode and operands") {
    SRLI instruction(Register::s6, Register::s7, 6);

    REQUIRE(instruction.opcode == Opcode::SRLI);
    REQUIRE(instruction.rd == Register::s6);
    REQUIRE(instruction.rs1 == Register::s7);
    REQUIRE(instruction.imm == 6);
}

TEST_CASE("SRAI stores opcode and operands") {
    SRAI instruction(Register::s8, Register::s9, 7);

    REQUIRE(instruction.opcode == Opcode::SRAI);
    REQUIRE(instruction.rd == Register::s8);
    REQUIRE(instruction.rs1 == Register::s9);
    REQUIRE(instruction.imm == 7);
}

TEST_CASE("LUI stores opcode and operands") {
    LUI instruction(Register::s10, 1024);

    REQUIRE(instruction.opcode == Opcode::LUI);
    REQUIRE(instruction.rd == Register::s10);
    REQUIRE(instruction.imm == 1024);
}

TEST_CASE("LB stores opcode and operands") {
    LB instruction(Register::s11, Register::t0, 128);

    REQUIRE(instruction.opcode == Opcode::LB);
    REQUIRE(instruction.rd == Register::s11);
    REQUIRE(instruction.rs1 == Register::t0);
    REQUIRE(instruction.imm == 128);
}

TEST_CASE("LH stores opcode and operands") {
    LH instruction(Register::t1, Register::t2, 256);

    REQUIRE(instruction.opcode == Opcode::LH);
    REQUIRE(instruction.rd == Register::t1);
    REQUIRE(instruction.rs1 == Register::t2);
    REQUIRE(instruction.imm == 256);
}

TEST_CASE("LW stores opcode and operands") {
    LW instruction(Register::t3, Register::t4, 512);

    REQUIRE(instruction.opcode == Opcode::LW);
    REQUIRE(instruction.rd == Register::t3);
    REQUIRE(instruction.rs1 == Register::t4);
    REQUIRE(instruction.imm == 512);
}

TEST_CASE("LD stores opcode and operands") {
    LD instruction(Register::t5, Register::t6, 1024);

    REQUIRE(instruction.opcode == Opcode::LD);
    REQUIRE(instruction.rd == Register::t5);
    REQUIRE(instruction.rs1 == Register::t6);
    REQUIRE(instruction.imm == 1024);
}

TEST_CASE("LBU stores opcode and operands") {
    LBU instruction(Register::a0, Register::a1, 64);

    REQUIRE(instruction.opcode == Opcode::LBU);
    REQUIRE(instruction.rd == Register::a0);
    REQUIRE(instruction.rs1 == Register::a1);
    REQUIRE(instruction.imm == 64);
}

TEST_CASE("LHU stores opcode and operands") {
    LHU instruction(Register::a2, Register::a3, 96);

    REQUIRE(instruction.opcode == Opcode::LHU);
    REQUIRE(instruction.rd == Register::a2);
    REQUIRE(instruction.rs1 == Register::a3);
    REQUIRE(instruction.imm == 96);
}

TEST_CASE("LWU stores opcode and operands") {
    LWU instruction(Register::a4, Register::a5, 160);

    REQUIRE(instruction.opcode == Opcode::LWU);
    REQUIRE(instruction.rd == Register::a4);
    REQUIRE(instruction.rs1 == Register::a5);
    REQUIRE(instruction.imm == 160);
}

TEST_CASE("ECALL stores opcode") {
    ECALL instruction;

    REQUIRE(instruction.opcode == Opcode::ECALL);
    REQUIRE(instruction.rd == Register::zero);
    REQUIRE(instruction.rs1 == Register::zero);
    REQUIRE(instruction.imm == 0);
}

TEST_CASE("EBREAK stores opcode") {
    EBREAK instruction;

    REQUIRE(instruction.opcode == Opcode::EBREAK);
    REQUIRE(instruction.rd == Register::zero);
    REQUIRE(instruction.rs1 == Register::zero);
    REQUIRE(instruction.imm == 0);
}

TEST_CASE("CSRRW stores opcode and operands") {
    CSRRW instruction(Register::a0, Register::a1, 3072);

    REQUIRE(instruction.opcode == Opcode::CSRRW);
    REQUIRE(instruction.rd == Register::a0);
    REQUIRE(instruction.rs1 == Register::a1);
    REQUIRE(instruction.imm == 3072);
}

TEST_CASE("CSRRS stores opcode and operands") {
    CSRRS instruction(Register::a2, Register::a3, 3073);

    REQUIRE(instruction.opcode == Opcode::CSRRS);
    REQUIRE(instruction.rd == Register::a2);
    REQUIRE(instruction.rs1 == Register::a3);
    REQUIRE(instruction.imm == 3073);
}

TEST_CASE("CSRRC stores opcode and operands") {
    CSRRC instruction(Register::a4, Register::a5, 3074);

    REQUIRE(instruction.opcode == Opcode::CSRRC);
    REQUIRE(instruction.rd == Register::a4);
    REQUIRE(instruction.rs1 == Register::a5);
    REQUIRE(instruction.imm == 3074);
}
