cmake_minimum_required(VERSION 3.16)

project(rvsim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

add_library(rvsim
    src/isa/addi.cc
    src/isa/andi.cc
    src/isa/instruction.cc
    src/isa/instruction_type_i.cc
    src/isa/ori.cc
    src/isa/slli.cc
    src/isa/slti.cc
    src/isa/sltiu.cc
    src/isa/xori.cc
)

target_include_directories(rvsim
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

add_executable(main
    apps/main.cc
)

target_link_libraries(main
    PRIVATE rvsim
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

    add_executable(rvsim_tests
        tests/unit/instruction_test.cc
        tests/unit/register_test.cc
    )

    target_link_libraries(rvsim_tests
        PRIVATE
        rvsim
        Catch2::Catch2WithMain
    )

    include(Catch)
    catch_discover_tests(rvsim_tests)
endif()
