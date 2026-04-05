cmake_minimum_required(VERSION 3.16)

project(rvsim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(rvsim
    src/isa/instruction.cc
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
