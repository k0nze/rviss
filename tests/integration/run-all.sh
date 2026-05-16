#!/usr/bin/env sh
set -eu

repo_root=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)

"${repo_root}/tests/integration/run-riscv-examples.sh"

"${repo_root}/examples/linux/buildroot/fetch.sh"
"${repo_root}/examples/linux/buildroot/build.sh"
"${repo_root}/tests/integration/boot-buildroot-linux.sh"
