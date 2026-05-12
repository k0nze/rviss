OUTPUT_ARCH("riscv")
ENTRY(_start)

MEMORY
{
  if_clint (wa) : ORIGIN = 0x02000000, LENGTH = 768K
  if_htif  (wa) : ORIGIN = 0x020c0000, LENGTH = 512K
  if_ram   (wxa): ORIGIN = 0x80000000, LENGTH = 512M
}

SECTIONS
{
  . = ORIGIN(if_ram);

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
    *(.bss)
    *(.bss.*)
    *(COMMON)
  } > if_ram
}
