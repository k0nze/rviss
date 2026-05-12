.section .text.start
.global _start

_start:
  la gp, __global_pointer$
  la sp, _stack

  la t0, __bss_start
  la t1, __bss_end

clear_bss:
  bgeu t0, t1, call_main
  sd zero, 0(t0)
  addi t0, t0, 8
  j clear_bss

call_main:
  call main
  tail htif_exit

.section .text
.global htif_exit
htif_exit:
  la t0, tohost
  sll a0, a0, 1
  ori a0, a0, 1

1:
  sw a0, 0(t0)
  sw zero, 4(t0)
  j 1b

.global htif_putc
htif_putc:
  la t0, tohost
  sw a0, 0(t0)
  li a0, 0x01010000
  sw a0, 4(t0)
  ret

.section .bss.mmio.htif
.balign 8
.global tohost
tohost:
  .dword 0

.balign 8
.global fromhost
fromhost:
  .dword 0
