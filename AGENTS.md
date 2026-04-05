# RVSIM

## Project Scope

This project is intended to build a purely functional RISC-V instruction set simulator in C++ 17 to learn more about RISC-V and eventually be able to boot a Linux kernel while the performance is a secondary goal.

## Structure

* `src` contains the implementation
* `include` contains the public headers
* `include/rvsim` contains the public library interface
* `include/rvsim/rvsim.h` is the umbrella header intended for apps
* `include/rvsim/isa` contains ISA-related public headers
* `tests` contains the tests
* `tests/unit` contains Catch2-based unit tests
* `apps` contains examples of how to use the instruction set simulator
* `build` contains the build output generated with `cmake` and `ninja`

## Build

From the project root:

* `cmake -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON`
* `cmake --build build`

## Testing

The project uses Catch2 for unit tests and CTest for test execution.

From the project root:

* `cmake -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON`
* `cmake --build build`
* `ctest --test-dir build --output-on-failure`
