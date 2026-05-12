OUTPUT_ARCH("riscv")
ENTRY(_start)

__STACK_SIZE = 0x2000;

MEMORY
{
  if_clint (wa) : ORIGIN = 0x02000000, LENGTH = 768K
  if_htif  (wa) : ORIGIN = 0x020c0000, LENGTH = 512K
  if_ram   (wxa): ORIGIN = 0x80000000, LENGTH = 512M
}

SECTIONS
{
  . = ORIGIN(if_ram);

  .stack ALIGN(16) (NOLOAD) : {
    _stack_end = .;
    . += __STACK_SIZE;
    . = ALIGN(16);
    _stack = .;
  } > if_ram

  __global_pointer$ = .;

  .text : {
    *(.text)
    *(.text.*)
  } > if_ram

  .rodata : {
    *(.rodata)
    *(.rodata.*)
  } > if_ram

  .data : {
    *(.data)
    *(.data.*)
  } > if_ram

  .bss.mmio.htif (NOLOAD) : {
    *(.bss.mmio.htif)
  } > if_htif

  .bss (NOLOAD) : {
    __bss_start = .;
    *(.bss)
    *(.bss.*)
    *(COMMON)
    . = ALIGN(8);
    __bss_end = .;
  } > if_ram
}
