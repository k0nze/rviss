find_program(HARBOR_RISCV_GCC riscv64-elf-gcc)
find_program(HARBOR_RISCV_AS riscv64-elf-as)
find_program(HARBOR_RISCV_LD riscv64-elf-ld)
find_program(HARBOR_RISCV_OBJDUMP riscv64-elf-objdump)
find_program(HARBOR_RISCV_READELF riscv64-elf-readelf)

if(NOT HARBOR_RISCV_GCC)
  message(FATAL_ERROR "riscv64-elf-gcc not found. Install the RISC-V bare-metal toolchain, for example with Homebrew: brew install riscv64-elf-gcc")
endif()

if(NOT HARBOR_RISCV_AS)
  message(FATAL_ERROR "riscv64-elf-as not found. Install the RISC-V bare-metal binutils package.")
endif()

if(NOT HARBOR_RISCV_LD)
  message(FATAL_ERROR "riscv64-elf-ld not found. Install the RISC-V bare-metal binutils package.")
endif()

if(NOT HARBOR_RISCV_OBJDUMP)
  message(FATAL_ERROR "riscv64-elf-objdump not found. Install the RISC-V bare-metal binutils package.")
endif()

if(NOT HARBOR_RISCV_READELF)
  message(FATAL_ERROR "riscv64-elf-readelf not found. Install the RISC-V bare-metal binutils package.")
endif()

message(STATUS "Found RISC-V bare-metal GCC: ${HARBOR_RISCV_GCC}")
message(STATUS "Found RISC-V bare-metal assembler: ${HARBOR_RISCV_AS}")
message(STATUS "Found RISC-V bare-metal linker: ${HARBOR_RISCV_LD}")
message(STATUS "Found RISC-V bare-metal objdump: ${HARBOR_RISCV_OBJDUMP}")
message(STATUS "Found RISC-V bare-metal readelf: ${HARBOR_RISCV_READELF}")

set(HARBOR_BAREMETAL_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(HARBOR_BAREMETAL_LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/linker/rv64-baremetal.ld")

set(HARBOR_BAREMETAL_MINIMAL_ELF "${HARBOR_BAREMETAL_BUILD_DIR}/minimal/exit.elf")
set(HARBOR_BAREMETAL_MINIMAL_MAP "${HARBOR_BAREMETAL_BUILD_DIR}/minimal/exit.map")
set(HARBOR_BAREMETAL_HELLO_ELF "${HARBOR_BAREMETAL_BUILD_DIR}/hello/hello.elf")
set(HARBOR_BAREMETAL_HELLO_MAP "${HARBOR_BAREMETAL_BUILD_DIR}/hello/hello.map")

add_custom_command(
  OUTPUT "${HARBOR_BAREMETAL_MINIMAL_ELF}"
  COMMAND "${CMAKE_COMMAND}" -E make_directory "${HARBOR_BAREMETAL_BUILD_DIR}/minimal"
  COMMAND
    "${HARBOR_RISCV_GCC}"
      -march=rv64gc
      -mabi=lp64
      -nostdlib
      -nostartfiles
      "-T${HARBOR_BAREMETAL_LINKER_SCRIPT}"
      "-Wl,--no-relax"
      "-Wl,--no-warn-rwx-segments"
      "-Wl,-Map,${HARBOR_BAREMETAL_MINIMAL_MAP}"
      -o "${HARBOR_BAREMETAL_MINIMAL_ELF}"
      "${CMAKE_CURRENT_SOURCE_DIR}/minimal/exit.S"
  DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/minimal/exit.S"
    "${HARBOR_BAREMETAL_LINKER_SCRIPT}"
  COMMENT "Building minimal RV64GC bare-metal ELF"
  VERBATIM
)

add_custom_target(harbor_baremetal_minimal
  DEPENDS "${HARBOR_BAREMETAL_MINIMAL_ELF}"
)

add_custom_target(harbor_run_baremetal_minimal
  COMMAND "${CMAKE_COMMAND}" --build "${HARBOR_SAIL_RISCV_BINARY_DIR}" --target sail_riscv_sim
  COMMAND
    "${HARBOR_SAIL_RISCV_BINARY_DIR}/c_emulator/sail_riscv_sim"
      --inst-limit 100
      "${HARBOR_BAREMETAL_MINIMAL_ELF}"
  DEPENDS harbor_baremetal_minimal
  COMMENT "Running minimal RV64GC bare-metal ELF with Sail RISC-V"
  VERBATIM
)

add_custom_command(
  OUTPUT "${HARBOR_BAREMETAL_HELLO_ELF}"
  COMMAND "${CMAKE_COMMAND}" -E make_directory "${HARBOR_BAREMETAL_BUILD_DIR}/hello"
  COMMAND
    "${HARBOR_RISCV_GCC}"
      -march=rv64gc
      -mabi=lp64
      -mcmodel=medany
      -ffreestanding
      -fno-builtin
      -Wall
      -Wextra
      -nostdlib
      -nostartfiles
      "-I${CMAKE_CURRENT_SOURCE_DIR}/c_runtime"
      "-T${HARBOR_BAREMETAL_LINKER_SCRIPT}"
      "-Wl,--no-relax"
      "-Wl,--no-warn-rwx-segments"
      "-Wl,-Map,${HARBOR_BAREMETAL_HELLO_MAP}"
      -o "${HARBOR_BAREMETAL_HELLO_ELF}"
      "${CMAKE_CURRENT_SOURCE_DIR}/c_runtime/start.S"
      "${CMAKE_CURRENT_SOURCE_DIR}/c_runtime/runtime.c"
      "${CMAKE_CURRENT_SOURCE_DIR}/hello/main.c"
  DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/c_runtime/start.S"
    "${CMAKE_CURRENT_SOURCE_DIR}/c_runtime/runtime.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/c_runtime/runtime.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/hello/main.c"
    "${HARBOR_BAREMETAL_LINKER_SCRIPT}"
  COMMENT "Building hello RV64GC bare-metal ELF"
  VERBATIM
)

add_custom_target(harbor_baremetal_hello
  DEPENDS "${HARBOR_BAREMETAL_HELLO_ELF}"
)

add_custom_target(harbor_run_baremetal_hello
  COMMAND "${CMAKE_COMMAND}" --build "${HARBOR_SAIL_RISCV_BINARY_DIR}" --target sail_riscv_sim
  COMMAND
    "${HARBOR_SAIL_RISCV_BINARY_DIR}/c_emulator/sail_riscv_sim"
      --inst-limit 10000
      "${HARBOR_BAREMETAL_HELLO_ELF}"
  DEPENDS harbor_baremetal_hello
  COMMENT "Running hello RV64GC bare-metal ELF with Sail RISC-V"
  VERBATIM
)
