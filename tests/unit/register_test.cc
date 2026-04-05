#include <catch2/catch_test_macros.hpp>

#include "rviss/rviss.h"

TEST_CASE("Canonical registers map to register numbers 0 through 31") {
    REQUIRE(static_cast<int>(Register::x0) == 0);
    REQUIRE(static_cast<int>(Register::x1) == 1);
    REQUIRE(static_cast<int>(Register::x2) == 2);
    REQUIRE(static_cast<int>(Register::x3) == 3);
    REQUIRE(static_cast<int>(Register::x4) == 4);
    REQUIRE(static_cast<int>(Register::x5) == 5);
    REQUIRE(static_cast<int>(Register::x6) == 6);
    REQUIRE(static_cast<int>(Register::x7) == 7);
    REQUIRE(static_cast<int>(Register::x8) == 8);
    REQUIRE(static_cast<int>(Register::x9) == 9);
    REQUIRE(static_cast<int>(Register::x10) == 10);
    REQUIRE(static_cast<int>(Register::x11) == 11);
    REQUIRE(static_cast<int>(Register::x12) == 12);
    REQUIRE(static_cast<int>(Register::x13) == 13);
    REQUIRE(static_cast<int>(Register::x14) == 14);
    REQUIRE(static_cast<int>(Register::x15) == 15);
    REQUIRE(static_cast<int>(Register::x16) == 16);
    REQUIRE(static_cast<int>(Register::x17) == 17);
    REQUIRE(static_cast<int>(Register::x18) == 18);
    REQUIRE(static_cast<int>(Register::x19) == 19);
    REQUIRE(static_cast<int>(Register::x20) == 20);
    REQUIRE(static_cast<int>(Register::x21) == 21);
    REQUIRE(static_cast<int>(Register::x22) == 22);
    REQUIRE(static_cast<int>(Register::x23) == 23);
    REQUIRE(static_cast<int>(Register::x24) == 24);
    REQUIRE(static_cast<int>(Register::x25) == 25);
    REQUIRE(static_cast<int>(Register::x26) == 26);
    REQUIRE(static_cast<int>(Register::x27) == 27);
    REQUIRE(static_cast<int>(Register::x28) == 28);
    REQUIRE(static_cast<int>(Register::x29) == 29);
    REQUIRE(static_cast<int>(Register::x30) == 30);
    REQUIRE(static_cast<int>(Register::x31) == 31);
}

TEST_CASE("ABI register names map to their canonical registers") {
    REQUIRE(Register::zero == Register::x0);
    REQUIRE(Register::ra == Register::x1);
    REQUIRE(Register::sp == Register::x2);
    REQUIRE(Register::gp == Register::x3);
    REQUIRE(Register::tp == Register::x4);
    REQUIRE(Register::t0 == Register::x5);
    REQUIRE(Register::t1 == Register::x6);
    REQUIRE(Register::t2 == Register::x7);
    REQUIRE(Register::s0 == Register::x8);
    REQUIRE(Register::fp == Register::x8);
    REQUIRE(Register::s1 == Register::x9);
    REQUIRE(Register::a0 == Register::x10);
    REQUIRE(Register::a1 == Register::x11);
    REQUIRE(Register::a2 == Register::x12);
    REQUIRE(Register::a3 == Register::x13);
    REQUIRE(Register::a4 == Register::x14);
    REQUIRE(Register::a5 == Register::x15);
    REQUIRE(Register::a6 == Register::x16);
    REQUIRE(Register::a7 == Register::x17);
    REQUIRE(Register::s2 == Register::x18);
    REQUIRE(Register::s3 == Register::x19);
    REQUIRE(Register::s4 == Register::x20);
    REQUIRE(Register::s5 == Register::x21);
    REQUIRE(Register::s6 == Register::x22);
    REQUIRE(Register::s7 == Register::x23);
    REQUIRE(Register::s8 == Register::x24);
    REQUIRE(Register::s9 == Register::x25);
    REQUIRE(Register::s10 == Register::x26);
    REQUIRE(Register::s11 == Register::x27);
    REQUIRE(Register::t3 == Register::x28);
    REQUIRE(Register::t4 == Register::x29);
    REQUIRE(Register::t5 == Register::x30);
    REQUIRE(Register::t6 == Register::x31);
}
