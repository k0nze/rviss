# Bare-Metal Examples

This directory contains Harbor-owned bare-metal RISC-V programs used to explore
and validate the Sail RISC-V `c_emulator` flow.

The examples are intentionally kept outside `external/sail-riscv` so they can
evolve with Harbor without modifying upstream submodules.

## Layout

- `minimal/`: smallest programs used to validate that an ELF can be executed.
- `hello/`: small C programs used once the C runtime startup path is available.
- `c_runtime/`: startup code needed before entering C code.
- `linker/`: linker scripts for the bare-metal examples.

The compile and run flow is still TODO. It should be added here after the
expected RISC-V cross-toolchain and `c_emulator` invocation are confirmed.

