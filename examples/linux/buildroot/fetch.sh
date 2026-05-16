#!/usr/bin/env sh
set -eu

repo_root=$(CDPATH= cd -- "$(dirname -- "$0")/../../.." && pwd)
docker_cmd="${DOCKER:-docker}"
image_name="${HARBOR_EXAMPLES_DOCKER_IMAGE:-harbor-examples-builder:latest}"
source_volume="${HARBOR_BUILDROOT_SOURCE_VOLUME:-harbor-buildroot-source}"
in_container="${HARBOR_IN_DOCKER:-0}"

if [ "${in_container}" != "1" ]; then
  if ! command -v "${docker_cmd}" >/dev/null 2>&1; then
    echo "Docker executable not found: ${docker_cmd}" >&2
    exit 1
  fi

  if ! "${docker_cmd}" info >/dev/null 2>&1; then
    echo "Docker daemon is not reachable. Start Docker Desktop and try again." >&2
    exit 1
  fi

  if ! "${docker_cmd}" image inspect "${image_name}" >/dev/null 2>&1; then
    echo "Missing Docker image: ${image_name}" >&2
    echo "Build it first with the command documented in README.md." >&2
    exit 1
  fi

  # Keep Buildroot downloads and extracted sources in a Docker volume.
  "${docker_cmd}" run --rm \
    -v "${source_volume}:/buildroot-source" \
    "${image_name}" \
    sh -c "mkdir -p /buildroot-source && chown -R $(id -u):$(id -g) /buildroot-source"

  "${docker_cmd}" run --rm \
    -u "$(id -u):$(id -g)" \
    -v "${repo_root}:/work:ro" \
    -v "${source_volume}:/buildroot-source" \
    -w /work \
    -e HARBOR_IN_DOCKER=1 \
    -e BUILDROOT_VERSION="${BUILDROOT_VERSION:-}" \
    -e BUILDROOT_SOURCE_DIR="${BUILDROOT_SOURCE_DIR:-}" \
    "${image_name}" \
    sh /work/examples/linux/buildroot/fetch.sh

  exit $?
fi

# Keep the Buildroot version in a small file so the example is reproducible.
version="${BUILDROOT_VERSION:-$(cat "${repo_root}/examples/linux/buildroot/buildroot.version")}"

# Store downloaded and extracted Buildroot sources outside Git-tracked paths.
download_dir="/buildroot-source/downloads"
source_dir="${BUILDROOT_SOURCE_DIR:-/buildroot-source/buildroot-${version}}"
archive="${download_dir}/buildroot-${version}.tar.xz"
url="https://buildroot.org/downloads/buildroot-${version}.tar.xz"

if [ -d "${source_dir}" ]; then
  echo "Buildroot already available: ${source_dir}"
  exit 0
fi

mkdir -p "${download_dir}" "/buildroot-source"

# Download the pinned release tarball only once.
if [ ! -f "${archive}" ]; then
  echo "Downloading ${url}"
  curl --location "${url}" --output "${archive}"
fi

# Extract Buildroot into the source volume so Harbor does not vendor it.
echo "Extracting ${archive}"
tar -C "/buildroot-source" -xf "${archive}"

echo "Buildroot source: ${source_dir}"
