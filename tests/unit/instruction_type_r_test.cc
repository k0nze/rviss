#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

TEST_CASE("ADD stores opcode and operands") {
    ADD instruction(Register::t3, Register::t4, Register::t5);

    REQUIRE(instruction.opcode == Opcode::ADD);
    REQUIRE(instruction.rd == Register::t3);
    REQUIRE(instruction.rs1 == Register::t4);
    REQUIRE(instruction.rs2 == Register::t5);
}

TEST_CASE("SUB stores opcode and operands") {
    SUB instruction(Register::t6, Register::a0, Register::a1);

    REQUIRE(instruction.opcode == Opcode::SUB);
    REQUIRE(instruction.rd == Register::t6);
    REQUIRE(instruction.rs1 == Register::a0);
    REQUIRE(instruction.rs2 == Register::a1);
}

TEST_CASE("SLL stores opcode and operands") {
    SLL instruction(Register::a2, Register::a3, Register::a4);

    REQUIRE(instruction.opcode == Opcode::SLL);
    REQUIRE(instruction.rd == Register::a2);
    REQUIRE(instruction.rs1 == Register::a3);
    REQUIRE(instruction.rs2 == Register::a4);
}

TEST_CASE("SLT stores opcode and operands") {
    SLT instruction(Register::a5, Register::a6, Register::a7);

    REQUIRE(instruction.opcode == Opcode::SLT);
    REQUIRE(instruction.rd == Register::a5);
    REQUIRE(instruction.rs1 == Register::a6);
    REQUIRE(instruction.rs2 == Register::a7);
}

TEST_CASE("SLTU stores opcode and operands") {
    SLTU instruction(Register::s0, Register::s1, Register::s2);

    REQUIRE(instruction.opcode == Opcode::SLTU);
    REQUIRE(instruction.rd == Register::s0);
    REQUIRE(instruction.rs1 == Register::s1);
    REQUIRE(instruction.rs2 == Register::s2);
}

TEST_CASE("XOR stores opcode and operands") {
    XOR instruction(Register::s3, Register::s4, Register::s5);

    REQUIRE(instruction.opcode == Opcode::XOR);
    REQUIRE(instruction.rd == Register::s3);
    REQUIRE(instruction.rs1 == Register::s4);
    REQUIRE(instruction.rs2 == Register::s5);
}

TEST_CASE("SRL stores opcode and operands") {
    SRL instruction(Register::s6, Register::s7, Register::s8);

    REQUIRE(instruction.opcode == Opcode::SRL);
    REQUIRE(instruction.rd == Register::s6);
    REQUIRE(instruction.rs1 == Register::s7);
    REQUIRE(instruction.rs2 == Register::s8);
}

TEST_CASE("SRA stores opcode and operands") {
    SRA instruction(Register::s9, Register::s10, Register::s11);

    REQUIRE(instruction.opcode == Opcode::SRA);
    REQUIRE(instruction.rd == Register::s9);
    REQUIRE(instruction.rs1 == Register::s10);
    REQUIRE(instruction.rs2 == Register::s11);
}

TEST_CASE("OR stores opcode and operands") {
    OR instruction(Register::t0, Register::t1, Register::t2);

    REQUIRE(instruction.opcode == Opcode::OR);
    REQUIRE(instruction.rd == Register::t0);
    REQUIRE(instruction.rs1 == Register::t1);
    REQUIRE(instruction.rs2 == Register::t2);
}

TEST_CASE("AND stores opcode and operands") {
    AND instruction(Register::t3, Register::t4, Register::t5);

    REQUIRE(instruction.opcode == Opcode::AND);
    REQUIRE(instruction.rd == Register::t3);
    REQUIRE(instruction.rs1 == Register::t4);
    REQUIRE(instruction.rs2 == Register::t5);
}

TEST_CASE("ADDW stores opcode and operands") {
    ADDW instruction(Register::a0, Register::a1, Register::a2);

    REQUIRE(instruction.opcode == Opcode::ADDW);
    REQUIRE(instruction.rd == Register::a0);
    REQUIRE(instruction.rs1 == Register::a1);
    REQUIRE(instruction.rs2 == Register::a2);
}

TEST_CASE("SUBW stores opcode and operands") {
    SUBW instruction(Register::a3, Register::a4, Register::a5);

    REQUIRE(instruction.opcode == Opcode::SUBW);
    REQUIRE(instruction.rd == Register::a3);
    REQUIRE(instruction.rs1 == Register::a4);
    REQUIRE(instruction.rs2 == Register::a5);
}

TEST_CASE("SLLW stores opcode and operands") {
    SLLW instruction(Register::a6, Register::a7, Register::s0);

    REQUIRE(instruction.opcode == Opcode::SLLW);
    REQUIRE(instruction.rd == Register::a6);
    REQUIRE(instruction.rs1 == Register::a7);
    REQUIRE(instruction.rs2 == Register::s0);
}

TEST_CASE("SRLW stores opcode and operands") {
    SRLW instruction(Register::s1, Register::s2, Register::s3);

    REQUIRE(instruction.opcode == Opcode::SRLW);
    REQUIRE(instruction.rd == Register::s1);
    REQUIRE(instruction.rs1 == Register::s2);
    REQUIRE(instruction.rs2 == Register::s3);
}

TEST_CASE("SRAW stores opcode and operands") {
    SRAW instruction(Register::s4, Register::s5, Register::s6);

    REQUIRE(instruction.opcode == Opcode::SRAW);
    REQUIRE(instruction.rd == Register::s4);
    REQUIRE(instruction.rs1 == Register::s5);
    REQUIRE(instruction.rs2 == Register::s6);
}

TEST_CASE("MUL stores opcode and operands") {
    MUL instruction(Register::s7, Register::s8, Register::s9);

    REQUIRE(instruction.opcode == Opcode::MUL);
    REQUIRE(instruction.rd == Register::s7);
    REQUIRE(instruction.rs1 == Register::s8);
    REQUIRE(instruction.rs2 == Register::s9);
}

TEST_CASE("MULH stores opcode and operands") {
    MULH instruction(Register::s10, Register::s11, Register::t0);

    REQUIRE(instruction.opcode == Opcode::MULH);
    REQUIRE(instruction.rd == Register::s10);
    REQUIRE(instruction.rs1 == Register::s11);
    REQUIRE(instruction.rs2 == Register::t0);
}

TEST_CASE("MULHSU stores opcode and operands") {
    MULHSU instruction(Register::t1, Register::t2, Register::t3);

    REQUIRE(instruction.opcode == Opcode::MULHSU);
    REQUIRE(instruction.rd == Register::t1);
    REQUIRE(instruction.rs1 == Register::t2);
    REQUIRE(instruction.rs2 == Register::t3);
}

TEST_CASE("MULHU stores opcode and operands") {
    MULHU instruction(Register::t4, Register::t5, Register::t6);

    REQUIRE(instruction.opcode == Opcode::MULHU);
    REQUIRE(instruction.rd == Register::t4);
    REQUIRE(instruction.rs1 == Register::t5);
    REQUIRE(instruction.rs2 == Register::t6);
}

TEST_CASE("DIV stores opcode and operands") {
    DIV instruction(Register::a0, Register::a1, Register::a2);

    REQUIRE(instruction.opcode == Opcode::DIV);
    REQUIRE(instruction.rd == Register::a0);
    REQUIRE(instruction.rs1 == Register::a1);
    REQUIRE(instruction.rs2 == Register::a2);
}

TEST_CASE("DIVU stores opcode and operands") {
    DIVU instruction(Register::a3, Register::a4, Register::a5);

    REQUIRE(instruction.opcode == Opcode::DIVU);
    REQUIRE(instruction.rd == Register::a3);
    REQUIRE(instruction.rs1 == Register::a4);
    REQUIRE(instruction.rs2 == Register::a5);
}

TEST_CASE("REM stores opcode and operands") {
    REM instruction(Register::a6, Register::a7, Register::s0);

    REQUIRE(instruction.opcode == Opcode::REM);
    REQUIRE(instruction.rd == Register::a6);
    REQUIRE(instruction.rs1 == Register::a7);
    REQUIRE(instruction.rs2 == Register::s0);
}

TEST_CASE("REMU stores opcode and operands") {
    REMU instruction(Register::s1, Register::s2, Register::s3);

    REQUIRE(instruction.opcode == Opcode::REMU);
    REQUIRE(instruction.rd == Register::s1);
    REQUIRE(instruction.rs1 == Register::s2);
    REQUIRE(instruction.rs2 == Register::s3);
}

TEST_CASE("MULW stores opcode and operands") {
    MULW instruction(Register::s4, Register::s5, Register::s6);

    REQUIRE(instruction.opcode == Opcode::MULW);
    REQUIRE(instruction.rd == Register::s4);
    REQUIRE(instruction.rs1 == Register::s5);
    REQUIRE(instruction.rs2 == Register::s6);
}

TEST_CASE("DIVW stores opcode and operands") {
    DIVW instruction(Register::s7, Register::s8, Register::s9);

    REQUIRE(instruction.opcode == Opcode::DIVW);
    REQUIRE(instruction.rd == Register::s7);
    REQUIRE(instruction.rs1 == Register::s8);
    REQUIRE(instruction.rs2 == Register::s9);
}

TEST_CASE("DIVUW stores opcode and operands") {
    DIVUW instruction(Register::s10, Register::s11, Register::t0);

    REQUIRE(instruction.opcode == Opcode::DIVUW);
    REQUIRE(instruction.rd == Register::s10);
    REQUIRE(instruction.rs1 == Register::s11);
    REQUIRE(instruction.rs2 == Register::t0);
}

TEST_CASE("REMW stores opcode and operands") {
    REMW instruction(Register::t1, Register::t2, Register::t3);

    REQUIRE(instruction.opcode == Opcode::REMW);
    REQUIRE(instruction.rd == Register::t1);
    REQUIRE(instruction.rs1 == Register::t2);
    REQUIRE(instruction.rs2 == Register::t3);
}

TEST_CASE("REMUW stores opcode and operands") {
    REMUW instruction(Register::t4, Register::t5, Register::t6);

    REQUIRE(instruction.opcode == Opcode::REMUW);
    REQUIRE(instruction.rd == Register::t4);
    REQUIRE(instruction.rs1 == Register::t5);
    REQUIRE(instruction.rs2 == Register::t6);
}
