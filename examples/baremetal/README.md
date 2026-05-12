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

## Minimal Example

Build the minimal RV64GC ELF:

```bash
cmake --build build --target harbor_baremetal_minimal
```

Equivalent manual build command:

```bash
mkdir -p build/examples/baremetal/minimal
riscv64-elf-gcc \
  -march=rv64gc \
  -mabi=lp64 \
  -nostdlib \
  -nostartfiles \
  -Texamples/baremetal/linker/rv64-baremetal.ld \
  -Wl,--no-relax \
  -Wl,-Map,build/examples/baremetal/minimal/exit.map \
  -o build/examples/baremetal/minimal/exit.elf \
  examples/baremetal/minimal/exit.S
```

Run it with Sail RISC-V:

```bash
cmake --build build --target harbor_run_baremetal_minimal
```

The example exits through Sail RISC-V's HTIF `tohost` mechanism. A successful
run prints `SUCCESS`.
