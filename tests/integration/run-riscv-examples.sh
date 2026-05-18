#!/usr/bin/env sh
set -eu

repo_root=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)

echo "[integration] Building RISC-V assembly minimal example"
"${repo_root}/examples/riscv/minimal/build.sh"

echo "[integration] Building RISC-V C hello example"
"${repo_root}/examples/riscv/hello/build.sh"

echo "[integration] Running RISC-V assembly minimal example"
"${repo_root}/examples/riscv/minimal/run.sh"

echo "[integration] Running RISC-V C hello example"
"${repo_root}/examples/riscv/hello/run.sh"
