#!/usr/bin/env sh
set -eu

repo_root=$(CDPATH= cd -- "$(dirname -- "$0")/../../.." && pwd)
if [ -n "${BUILD_DIR:-}" ]; then
  case "${BUILD_DIR}" in
    /*) host_build_dir="${BUILD_DIR}" ;;
    *) host_build_dir="${repo_root}/${BUILD_DIR}" ;;
  esac
else
  host_build_dir="${repo_root}/build/riscv"
fi
docker_cmd="${DOCKER:-docker}"
image_name="${HARBOR_EXAMPLES_DOCKER_IMAGE:-harbor-examples-builder}"

if ! command -v "${docker_cmd}" >/dev/null 2>&1; then
  echo "Docker executable not found: ${docker_cmd}" >&2
  exit 1
fi

if ! "${docker_cmd}" image inspect "${image_name}" >/dev/null 2>&1; then
  echo "Missing Docker image: ${image_name}" >&2
  echo "Build it first with the command documented in README.md." >&2
  exit 1
fi

case "${host_build_dir}" in
  "${repo_root}") container_build_dir="/work" ;;
  "${repo_root}"/*) container_build_dir="/work/${host_build_dir#"${repo_root}/"}" ;;
  *)
    echo "BUILD_DIR must be inside the repository when building in Docker: ${host_build_dir}" >&2
    exit 1
    ;;
esac

mkdir -p "${host_build_dir}"

# Run CMake inside the prepared example container.
"${docker_cmd}" run --rm \
  -u "$(id -u):$(id -g)" \
  -v "${repo_root}:/work" \
  -w /work \
  -e BUILD_DIR="${container_build_dir}" \
  "${image_name}" \
  sh -lc 'cmake -S /work -B "$BUILD_DIR" -G Ninja && cmake --build "$BUILD_DIR" --target harbor_riscv_c'
