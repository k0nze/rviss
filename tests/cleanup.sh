#!/usr/bin/env sh
set -eu

repo_root=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
docker_cmd="${DOCKER:-docker}"
image_name="${HARBOR_EXAMPLES_DOCKER_IMAGE:-harbor-examples-builder}"

# Only delete generated paths that live inside this repository.
remove_repo_path() {
  path=$1

  case "${path}" in
    "${repo_root}" | "${repo_root}/")
      echo "Refusing to remove repository root: ${path}" >&2
      exit 1
      ;;
    "${repo_root}"/*)
      if [ -e "${path}" ]; then
        rm -rf "${path}"
        echo "Removed ${path}"
      fi
      ;;
    *)
      echo "Refusing to remove path outside repository: ${path}" >&2
      exit 1
      ;;
  esac
}

# Remove generated build outputs and downloaded Buildroot sources.
remove_repo_path "${repo_root}/build"
remove_repo_path "${repo_root}/.buildroot"

# Remove the prepared example builder image if Docker is available.
if command -v "${docker_cmd}" >/dev/null 2>&1; then
  if "${docker_cmd}" image inspect "${image_name}" >/dev/null 2>&1; then
    "${docker_cmd}" image rm "${image_name}"
    echo "Removed Docker image ${image_name}"
  fi
else
  echo "Docker executable not found: ${docker_cmd}; skipping image cleanup" >&2
fi
