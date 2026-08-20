int main(void) { return 0; }

__attribute__((naked, noreturn)) void _reset(void) {
  // memset .bss to zero and copy .data to RAM
  extern long _sbss, _ebss, _sdata, _edata, _sidata;
  for (long *dst = &_sbss; dst < &_ebss; dst++)
    *dst = 0;
  for (long *dst = &_sdata, *src = &_sidata; dst < &_edata;)
    *dst++ = *src++;

  main();

  /* Infinite loop in case main returns */
  while (1)
    (void)0;
}
