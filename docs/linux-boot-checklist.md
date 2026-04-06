# Linux Boot Checklist for RVISS

This checklist is intended as a project reference for tracking what the simulator must eventually support in order to boot a Linux kernel on a RISC-V system.

Scope:
- Target: `RV64GC`
- Goal: boot a Linux kernel in a simulator
- Audience: project implementation planning and progress tracking

Primary references:
- Linux RISC-V boot requirements: <https://docs.kernel.org/next/arch/riscv/boot.html>
- Linux RISC-V boot image header: <https://docs.kernel.org/arch/riscv/boot-image-header.html>

Notes:
- `RV64GC` alone is not enough to boot Linux. Linux also requires privileged-architecture support and a Linux-capable machine model.
- This checklist is intentionally implementation-oriented, not a full architectural specification.

## 1. ISA Support

- [ ] Implement the full `RV64I` base integer ISA needed by Linux kernel code.
- [ ] Implement `M` extension instructions.
- [ ] Implement `A` extension instructions.
- [ ] Implement `C` extension decoding and execution.
- [ ] Implement `Zicsr` CSR instructions.
- [ ] Implement `Zifencei` instruction support.
- [ ] Decide whether floating-point (`F`/`D`) must be enabled at initial boot or can be deferred until later userspace goals.

## 2. Privileged Architecture

- [ ] Support privilege levels required by Linux, at minimum machine mode and supervisor mode.
- [ ] Implement trap and exception entry/return behavior.
- [ ] Implement `mstatus`, `sstatus`, `mepc`, `sepc`, `mcause`, `scause`, `mtval`, `stval`, `mtvec`, and `stvec`.
- [ ] Implement delegation CSRs such as `medeleg` and `mideleg`.
- [ ] Implement interrupt pending/enable CSRs such as `mie`, `mip`, `sie`, and `sip`.
- [ ] Implement `satp`.
- [ ] Implement `senvcfg`/related supervisor-visible state if required by the kernel configuration being booted.
- [ ] Implement `MRET`.
- [ ] Implement `SRET`.
- [ ] Implement `SFENCE.VMA`.
- [ ] Implement `WFI` behavior well enough for Linux idle/bring-up paths.

## 3. Virtual Memory and MMU

- [ ] Implement page-based virtual memory.
- [ ] Implement the `sv39` MMU mode expected by typical RV64 Linux systems.
- [ ] Consider `sv48` support later if broader compatibility is desired.
- [ ] Implement page-table walks.
- [ ] Implement permission checks for read/write/execute.
- [ ] Implement user/supervisor access rules.
- [ ] Implement accessed/dirty bit handling as expected by Linux.
- [ ] Implement instruction fetch through translated mappings.
- [ ] Implement address-misaligned, page-fault, and access-fault exceptions correctly.
- [ ] Implement TLB invalidation semantics required by `SFENCE.VMA`.

## 4. Boot Entry Contract

From the Linux boot requirements:
- [ ] Enter the kernel with `a0 = hartid`.
- [ ] Enter the kernel with `a1 = address of the devicetree`.
- [ ] Enter the kernel with `satp = 0` so paging is disabled on entry.

Platform/loader expectations:
- [ ] Load the kernel at a Linux-compatible physical address.
- [ ] Respect kernel alignment expectations.
- [ ] Provide a valid devicetree blob in memory.
- [ ] Ensure the kernel image/header handling matches Linux expectations.

## 5. Interrupts and Timers

- [ ] Model timer interrupts.
- [ ] Model software interrupts if needed for SMP bring-up.
- [ ] Model external interrupts.
- [ ] Provide a CLINT-like timer/software interrupt source or equivalent platform behavior.
- [ ] Provide a PLIC-like external interrupt controller or equivalent platform behavior.
- [ ] Route interrupts into the correct privileged CSRs and trap flow.

## 6. Memory Model and Atomics

- [ ] Provide RAM large enough for kernel, initramfs, and devicetree experiments.
- [ ] Implement atomic memory operations required by the `A` extension.
- [ ] Implement `LR/SC` reservation behavior correctly enough for kernel synchronization.
- [ ] Ensure memory ordering behavior is sufficient for Linux boot and early SMP synchronization.
- [ ] Handle MMIO regions distinctly from normal RAM.

## 7. Device/Platform Model

- [ ] Provide a machine model Linux can identify from the devicetree.
- [ ] Provide a UART for early console output.
- [ ] Provide timer devices described by the devicetree.
- [ ] Provide interrupt controller nodes in the devicetree.
- [ ] Provide RAM nodes and reserved-memory nodes correctly in the devicetree.
- [ ] Avoid exposing unsupported devices in the devicetree.

Useful minimum platform goal:
- [ ] RAM
- [ ] UART
- [ ] timer interrupt source
- [ ] interrupt controller
- [ ] devicetree handoff

## 8. SMP Support

- [ ] Decide whether the first Linux-boot milestone is single-hart or multi-hart.
- [ ] For a first milestone, support booting a uniprocessor kernel or booting only one hart.
- [ ] For SMP later, implement multiple harts with correct hart IDs.
- [ ] Implement inter-hart interrupt behavior needed by Linux SMP bring-up.
- [ ] Implement atomic synchronization behavior across harts.

## 9. Exception Correctness

- [ ] Illegal instruction exceptions
- [ ] Breakpoint exceptions
- [ ] Environment call exceptions
- [ ] Instruction address misaligned exceptions where architecturally relevant
- [ ] Load/store address misaligned exceptions
- [ ] Instruction/load/store access faults
- [ ] Instruction/load/store page faults

Linux boot is highly sensitive to precise exception behavior:
- [ ] Set `*cause`, `*epc`, and `*tval` correctly.
- [ ] Resume from traps correctly after handler return.

## 10. CSR Coverage Checklist

Minimum CSR areas to review against Linux needs:
- [ ] machine trap setup
- [ ] supervisor trap setup
- [ ] interrupt control
- [ ] exception delegation
- [ ] address translation (`satp`)
- [ ] cycle/time/instret exposure as needed by the chosen kernel configuration

## 11. Debugging and Bring-Up Aids

- [ ] Instruction trace logging
- [ ] CSR write/read tracing
- [ ] trap/exception logging
- [ ] page-table walk logging
- [ ] UART output capture
- [ ] deterministic stepping for early boot debugging

## 12. Suggested Milestones

### Milestone 1: User-level completeness
- [ ] Unprivileged `RV64GC` instruction execution is stable.

### Milestone 2: Supervisor-capable core
- [ ] Privileged CSRs, traps, and `satp` work.
- [ ] `sv39` address translation works.

### Milestone 3: Linux-compatible machine
- [ ] Kernel entry contract is correct.
- [ ] Devicetree handoff works.
- [ ] UART and timer/interrupt plumbing work.

### Milestone 4: First Linux boot
- [ ] Kernel reaches early console output.
- [ ] Kernel decompresses and enters early init.

### Milestone 5: Robust Linux bring-up
- [ ] Kernel reaches shell or init process.
- [ ] SMP and broader device support can be added incrementally.

## 13. Practical First-Boot Definition

A reasonable first success criterion for this project is:
- [ ] boot a single-hart `RV64` Linux kernel
- [ ] using a minimal devicetree
- [ ] with UART output visible
- [ ] with `sv39` paging enabled by the kernel
- [ ] without requiring full device emulation beyond RAM, timer, interrupt controller, and UART

## 14. Out of Scope for the First Linux-Boot Milestone

These can usually be deferred:
- [ ] full SMP support
- [ ] advanced PMU/counter support
- [ ] ACPI
- [ ] complex peripheral set
- [ ] disk/network devices
- [ ] UEFI
- [ ] full floating-point userspace validation

## 15. Current Project Comparison Checklist

Use this section as a quick status template during implementation:

- [ ] Full required unprivileged ISA implemented
- [ ] Privileged architecture implemented
- [ ] `sv39` MMU implemented
- [ ] Trap/interrupt flow implemented
- [ ] Linux entry register contract implemented
- [ ] Devicetree handoff implemented
- [ ] UART implemented
- [ ] Timer interrupt source implemented
- [ ] Interrupt controller implemented
- [ ] Single-hart Linux reaches early console
- [ ] Linux reaches `init`
