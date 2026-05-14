#!/usr/bin/env sh
set -eu

repo_root=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
build_dir="${BUILD_DIR:-${repo_root}/build}"

cmake -S "${repo_root}" -B "${build_dir}" -G Ninja
cmake --build "${build_dir}" --target harbor_riscv_assembly harbor_riscv_c

"${repo_root}/examples/riscv/minimal/run.sh"
"${repo_root}/examples/riscv/hello/run.sh"

