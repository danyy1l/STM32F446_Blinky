#include <stdint.h>

int main(void);
void _reset(void);

/* Import of Linker Script symbols, Declared as arrays to safely compare */
extern uint32_t _sbss[];
extern uint32_t _ebss[];
extern uint32_t _sdata[];
extern uint32_t _edata[];
extern uint32_t _sidata[];

typedef void (*Vector_Handler)(void);
extern const Vector_Handler tab[16 + 97];

/* Declaration of _estack as a function is standard in firmware, as it avoids
 * referencing with & or explicitly casting it */
extern void _estack(void);

/* Import of main function */
extern int main(void);

__attribute__((naked, noreturn)) void _reset(void) {
  uint32_t *dst;
  const uint32_t *src;

  dst = _sdata;
  src = _sidata;

  while (dst < _edata) {
    *dst = *src;
    ++dst;
    ++src;
  }

  dst = _sbss;
  while (dst < _ebss) {
    *dst = 0U;
    dst++;
  }

  /* Cast to void to ignore return value */
  (void)main();

  /* Infinite loop in case main returns */
  for (;;) {
    (void)0;
  }
}

// 16 standard and 97 STM32-specific handlers
__attribute__((section(".vectors"))) const Vector_Handler tab[16 + 97] = {
    _estack, /* Offset 0x00: Initial main stack pointer (MSP) */
    _reset   /* Offset 0x04: Reset_Handler */
             /* The other elements are initizalized to 0 by default */
};
