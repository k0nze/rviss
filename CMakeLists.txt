cmake_minimum_required(VERSION 3.16)

project(rviss LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

add_library(rviss
    src/isa/add.cc
    src/isa/addw.cc
    src/isa/addiw.cc
    src/isa/addi.cc
    src/isa/and.cc
    src/isa/andi.cc
    src/isa/csrrci.cc
    src/isa/csrrc.cc
    src/isa/csrrs.cc
    src/isa/csrrsi.cc
    src/isa/csrrwi.cc
    src/isa/csrrw.cc
    src/isa/div.cc
    src/isa/divu.cc
    src/isa/ecall.cc
    src/isa/ebreak.cc
    src/isa/fence.cc
    src/isa/fence_i.cc
    src/isa/instruction.cc
    src/isa/instruction_type_i.cc
    src/isa/instruction_type_r.cc
    src/isa/jalr.cc
    src/isa/lb.cc
    src/isa/lbu.cc
    src/isa/ld.cc
    src/isa/lh.cc
    src/isa/lhu.cc
    src/isa/lui.cc
    src/isa/lw.cc
    src/isa/lwu.cc
    src/isa/mret.cc
    src/isa/mul.cc
    src/isa/mulh.cc
    src/isa/mulhsu.cc
    src/isa/mulhu.cc
    src/isa/ori.cc
    src/isa/rem.cc
    src/isa/remu.cc
    src/isa/or.cc
    src/isa/sfence_vma.cc
    src/isa/sll.cc
    src/isa/sllw.cc
    src/isa/slli.cc
    src/isa/slliw.cc
    src/isa/slt.cc
    src/isa/srai.cc
    src/isa/sltu.cc
    src/isa/sra.cc
    src/isa/sraw.cc
    src/isa/sraiw.cc
    src/isa/sret.cc
    src/isa/slti.cc
    src/isa/sltiu.cc
    src/isa/sub.cc
    src/isa/subw.cc
    src/isa/srl.cc
    src/isa/srlw.cc
    src/isa/srli.cc
    src/isa/srliw.cc
    src/isa/uret.cc
    src/isa/wfi.cc
    src/isa/xor.cc
    src/isa/xori.cc
)

target_include_directories(rviss
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

add_executable(main
    apps/main.cc
)

target_link_libraries(main
    PRIVATE rviss
)

if(BUILD_TESTING)
    include(FetchContent)

    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.8.1
    )
    FetchContent_MakeAvailable(Catch2)

    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

    add_executable(rviss_tests
        tests/unit/instruction_test.cc
        tests/unit/register_test.cc
    )

    target_link_libraries(rviss_tests
        PRIVATE
        rviss
        Catch2::Catch2WithMain
    )

    include(Catch)
    catch_discover_tests(rviss_tests)
endif()
