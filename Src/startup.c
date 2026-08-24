#include <stdint.h>

/* Import of Linker Script symbols */
extern uint32_t _sbss, _ebss, _sdata, _edata, _sidata;

/* Declaration of _estack as a function is standard in firmware, as it avoids
 * referencing with & or explicitly casting it */
extern void _estack(void);

/* Import of main function */
extern int main(void);

__attribute__((naked, noreturn)) void _reset(void) {
  for (uint32_t *dst = &_sbss; dst < &_ebss; dst++)
    *dst = 0;
  for (uint32_t *dst = &_sdata, *src = &_sidata; dst < &_edata;)
    *dst++ = *src++;

  main();

  /* Infinite loop in case main returns */
  while (1)
    (void)0;
}

// 16 standard and 97 STM32-specific handlers
__attribute__((section(".vectors"))) void (*const tab[16 + 97])(void) = {
    _estack, /* Offset 0x00: Initial main stack pointer (MSP) */
    _reset   /* Offset 0x04: Reset_Handler */
             /* The other elements are initizalized to 0 by default */
};
