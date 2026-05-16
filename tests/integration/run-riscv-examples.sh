#!/usr/bin/env sh
set -eu

repo_root=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)

"${repo_root}/examples/riscv/minimal/build.sh"
"${repo_root}/examples/riscv/hello/build.sh"

"${repo_root}/examples/riscv/minimal/run.sh"
"${repo_root}/examples/riscv/hello/run.sh"
