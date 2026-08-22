/**
 * STM32F446RE Linker Script
 * Extracted from RM0390 - Section 2.3 Boot Configuration. Table 3
 */
ENTRY(_reset);

MEMORY {
  /* f446 memory mapping */
  FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 512K
  RAM(rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

_estack = ORIGIN(RAM) + LENGTH(RAM); /* Stack points to end of RAM */

SECTIONS {
  .vectors  : { KEEP(*(.vectors)) } > FLASH
  .text     : { *(.text*) }         > FLASH
  .rodata   : { *(.rodata*) }       > FLASH
  .data     : {
    _sdata = .; /* .data section start */
    *(.first_data)
    *(.data SORT(.data.*))
    _edata = .; /* .data section end */
  } > RAM AT > FLASH
  _sidata = LOADADDR(.data);
  .bss      : {
    _sbss = .;  /* .bss section start */
    *(.bss SORT(.bss.*) COMMON)
    _ebss = .;  /* .bss section end */
  } > RAM
