#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

TEST_CASE("LR_W stores opcode and operands") {
    LR_W instruction(Register::a0, Register::a1);

    REQUIRE(instruction.opcode == Opcode::LR_W);
    REQUIRE(instruction.rd == Register::a0);
    REQUIRE(instruction.rs1 == Register::a1);
    REQUIRE(instruction.rs2 == Register::zero);
}

TEST_CASE("SC_W stores opcode and operands") {
    SC_W instruction(Register::a2, Register::a3, Register::a4);

    REQUIRE(instruction.opcode == Opcode::SC_W);
    REQUIRE(instruction.rd == Register::a2);
    REQUIRE(instruction.rs1 == Register::a3);
    REQUIRE(instruction.rs2 == Register::a4);
}

TEST_CASE("AMOSWAP_W stores opcode and operands") {
    AMOSWAP_W instruction(Register::a5, Register::a6, Register::a7);

    REQUIRE(instruction.opcode == Opcode::AMOSWAP_W);
    REQUIRE(instruction.rd == Register::a5);
    REQUIRE(instruction.rs1 == Register::a6);
    REQUIRE(instruction.rs2 == Register::a7);
}

TEST_CASE("AMOADD_W stores opcode and operands") {
    AMOADD_W instruction(Register::s0, Register::s1, Register::s2);

    REQUIRE(instruction.opcode == Opcode::AMOADD_W);
    REQUIRE(instruction.rd == Register::s0);
    REQUIRE(instruction.rs1 == Register::s1);
    REQUIRE(instruction.rs2 == Register::s2);
}

TEST_CASE("AMOXOR_W stores opcode and operands") {
    AMOXOR_W instruction(Register::s3, Register::s4, Register::s5);

    REQUIRE(instruction.opcode == Opcode::AMOXOR_W);
    REQUIRE(instruction.rd == Register::s3);
    REQUIRE(instruction.rs1 == Register::s4);
    REQUIRE(instruction.rs2 == Register::s5);
}

TEST_CASE("AMOAND_W stores opcode and operands") {
    AMOAND_W instruction(Register::s6, Register::s7, Register::s8);

    REQUIRE(instruction.opcode == Opcode::AMOAND_W);
    REQUIRE(instruction.rd == Register::s6);
    REQUIRE(instruction.rs1 == Register::s7);
    REQUIRE(instruction.rs2 == Register::s8);
}

TEST_CASE("AMOOR_W stores opcode and operands") {
    AMOOR_W instruction(Register::s9, Register::s10, Register::s11);

    REQUIRE(instruction.opcode == Opcode::AMOOR_W);
    REQUIRE(instruction.rd == Register::s9);
    REQUIRE(instruction.rs1 == Register::s10);
    REQUIRE(instruction.rs2 == Register::s11);
}

TEST_CASE("AMOMIN_W stores opcode and operands") {
    AMOMIN_W instruction(Register::t0, Register::t1, Register::t2);

    REQUIRE(instruction.opcode == Opcode::AMOMIN_W);
    REQUIRE(instruction.rd == Register::t0);
    REQUIRE(instruction.rs1 == Register::t1);
    REQUIRE(instruction.rs2 == Register::t2);
}

TEST_CASE("AMOMAX_W stores opcode and operands") {
    AMOMAX_W instruction(Register::t3, Register::t4, Register::t5);

    REQUIRE(instruction.opcode == Opcode::AMOMAX_W);
    REQUIRE(instruction.rd == Register::t3);
    REQUIRE(instruction.rs1 == Register::t4);
    REQUIRE(instruction.rs2 == Register::t5);
}

TEST_CASE("AMOMINU_W stores opcode and operands") {
    AMOMINU_W instruction(Register::t6, Register::a0, Register::a1);

    REQUIRE(instruction.opcode == Opcode::AMOMINU_W);
    REQUIRE(instruction.rd == Register::t6);
    REQUIRE(instruction.rs1 == Register::a0);
    REQUIRE(instruction.rs2 == Register::a1);
}

TEST_CASE("AMOMAXU_W stores opcode and operands") {
    AMOMAXU_W instruction(Register::a2, Register::a3, Register::a4);

    REQUIRE(instruction.opcode == Opcode::AMOMAXU_W);
    REQUIRE(instruction.rd == Register::a2);
    REQUIRE(instruction.rs1 == Register::a3);
    REQUIRE(instruction.rs2 == Register::a4);
}

TEST_CASE("LR_D stores opcode and operands") {
    LR_D instruction(Register::a5, Register::a6);

    REQUIRE(instruction.opcode == Opcode::LR_D);
    REQUIRE(instruction.rd == Register::a5);
    REQUIRE(instruction.rs1 == Register::a6);
    REQUIRE(instruction.rs2 == Register::zero);
}

TEST_CASE("SC_D stores opcode and operands") {
    SC_D instruction(Register::a7, Register::s0, Register::s1);

    REQUIRE(instruction.opcode == Opcode::SC_D);
    REQUIRE(instruction.rd == Register::a7);
    REQUIRE(instruction.rs1 == Register::s0);
    REQUIRE(instruction.rs2 == Register::s1);
}

TEST_CASE("AMOSWAP_D stores opcode and operands") {
    AMOSWAP_D instruction(Register::s2, Register::s3, Register::s4);

    REQUIRE(instruction.opcode == Opcode::AMOSWAP_D);
    REQUIRE(instruction.rd == Register::s2);
    REQUIRE(instruction.rs1 == Register::s3);
    REQUIRE(instruction.rs2 == Register::s4);
}

TEST_CASE("AMOADD_D stores opcode and operands") {
    AMOADD_D instruction(Register::s5, Register::s6, Register::s7);

    REQUIRE(instruction.opcode == Opcode::AMOADD_D);
    REQUIRE(instruction.rd == Register::s5);
    REQUIRE(instruction.rs1 == Register::s6);
    REQUIRE(instruction.rs2 == Register::s7);
}

TEST_CASE("AMOXOR_D stores opcode and operands") {
    AMOXOR_D instruction(Register::s8, Register::s9, Register::s10);

    REQUIRE(instruction.opcode == Opcode::AMOXOR_D);
    REQUIRE(instruction.rd == Register::s8);
    REQUIRE(instruction.rs1 == Register::s9);
    REQUIRE(instruction.rs2 == Register::s10);
}

TEST_CASE("AMOAND_D stores opcode and operands") {
    AMOAND_D instruction(Register::s11, Register::t0, Register::t1);

    REQUIRE(instruction.opcode == Opcode::AMOAND_D);
    REQUIRE(instruction.rd == Register::s11);
    REQUIRE(instruction.rs1 == Register::t0);
    REQUIRE(instruction.rs2 == Register::t1);
}

TEST_CASE("AMOOR_D stores opcode and operands") {
    AMOOR_D instruction(Register::t2, Register::t3, Register::t4);

    REQUIRE(instruction.opcode == Opcode::AMOOR_D);
    REQUIRE(instruction.rd == Register::t2);
    REQUIRE(instruction.rs1 == Register::t3);
    REQUIRE(instruction.rs2 == Register::t4);
}

TEST_CASE("AMOMIN_D stores opcode and operands") {
    AMOMIN_D instruction(Register::t5, Register::t6, Register::a0);

    REQUIRE(instruction.opcode == Opcode::AMOMIN_D);
    REQUIRE(instruction.rd == Register::t5);
    REQUIRE(instruction.rs1 == Register::t6);
    REQUIRE(instruction.rs2 == Register::a0);
}

TEST_CASE("AMOMAX_D stores opcode and operands") {
    AMOMAX_D instruction(Register::a1, Register::a2, Register::a3);

    REQUIRE(instruction.opcode == Opcode::AMOMAX_D);
    REQUIRE(instruction.rd == Register::a1);
    REQUIRE(instruction.rs1 == Register::a2);
    REQUIRE(instruction.rs2 == Register::a3);
}

TEST_CASE("AMOMINU_D stores opcode and operands") {
    AMOMINU_D instruction(Register::a4, Register::a5, Register::a6);

    REQUIRE(instruction.opcode == Opcode::AMOMINU_D);
    REQUIRE(instruction.rd == Register::a4);
    REQUIRE(instruction.rs1 == Register::a5);
    REQUIRE(instruction.rs2 == Register::a6);
}

TEST_CASE("AMOMAXU_D stores opcode and operands") {
    AMOMAXU_D instruction(Register::a7, Register::s0, Register::s1);

    REQUIRE(instruction.opcode == Opcode::AMOMAXU_D);
    REQUIRE(instruction.rd == Register::a7);
    REQUIRE(instruction.rs1 == Register::s0);
    REQUIRE(instruction.rs2 == Register::s1);
}
