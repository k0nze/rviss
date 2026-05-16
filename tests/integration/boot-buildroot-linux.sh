#!/usr/bin/env sh
set -eu

repo_root=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
log_dir="${repo_root}/build/test-logs"
linux_boot_log="${log_dir}/buildroot-linux-boot.log"
linux_boot_timeout="${LINUX_BOOT_TIMEOUT_SECONDS:-120}"

mkdir -p "${log_dir}"
rm -f "${linux_boot_log}"

"${repo_root}/examples/linux/buildroot/run.sh" >"${linux_boot_log}" 2>&1 &
qemu_pid=$!

cleanup_qemu() {
  if kill -0 "${qemu_pid}" >/dev/null 2>&1; then
    kill "${qemu_pid}" >/dev/null 2>&1 || true
    wait "${qemu_pid}" >/dev/null 2>&1 || true
  fi
}

trap cleanup_qemu EXIT INT TERM

elapsed=0
while [ "${elapsed}" -lt "${linux_boot_timeout}" ]; do
  if grep -q "Run /init as init process" "${linux_boot_log}" 2>/dev/null; then
    cleanup_qemu
    trap - EXIT INT TERM
    echo "Linux reached init. Log: ${linux_boot_log}"
    exit 0
  fi

  if ! kill -0 "${qemu_pid}" >/dev/null 2>&1; then
    echo "QEMU exited before Linux reached init. Log: ${linux_boot_log}" >&2
    wait "${qemu_pid}" || true
    exit 1
  fi

  sleep 1
  elapsed=$((elapsed + 1))
done

echo "Timed out waiting for Linux init after ${linux_boot_timeout}s. Log: ${linux_boot_log}" >&2
exit 1
