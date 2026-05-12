.section .text
.global _start

_start:
  li a0, 0
  tail htif_exit

htif_exit:
  la t0, tohost
  sll a0, a0, 1
  ori a0, a0, 1

1:
  sw a0, 0(t0)
  sw zero, 4(t0)
  j 1b

.section .bss.mmio.htif
.balign 8
.global tohost
tohost:
  .dword 0

.balign 8
.global fromhost
fromhost:
  .dword 0
