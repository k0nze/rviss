FROM debian:trixie-slim

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
      bash \
      bc \
      binutils-riscv64-unknown-elf \
      bison \
      build-essential \
      ca-certificates \
      cmake \
      cpio \
      curl \
      file \
      flex \
      gawk \
      gcc-riscv64-unknown-elf \
      git \
      libncurses-dev \
      libssl-dev \
      libtool \
      m4 \
      make \
      ninja-build \
      patch \
      python3 \
      rsync \
      texinfo \
      unzip \
      util-linux \
      wget \
      xz-utils && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /work
