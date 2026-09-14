/**
 * @brief Hardware Abstraction Library for SysTick handling
 * * Contains SysTick abstraction implementations
 *
 * @author Danyyil Shykerynets
 * @file systick.c
 * @date 14-09-2026
 */

#include "../Inc/systick.h"
#include "../Inc/utils.h"
/**
 * NOTE: RM0390 Section 6.2.6: After a system reset, the HSI oscillator is
 * selected as the system clock This oscillator has a frequency of 16 MHz
 */

uint32_t SysTick_Config(uint32_t ticks) {
  HW_ASSERT(ticks > 0U);
  HW_ASSERT((ticks - 1U) <= SYSTICK_MAX_TICKS);

  if ((ticks - 1U) > SYSTICK_MAX_TICKS)
    return 1U;

  SYSTICK->CTRL = 0U;
  /* This is a redundant bit mask verification, if the system were
   * Safety-Critical it might be more useful, but in this case its optional */
  SYSTICK->LOAD = (ticks - 1U) & SYSTICK_LOAD_RELOAD_Msk;
  SYSTICK->VAL = 0U;

  /* Start systick timer */
  SYSTICK->CTRL = (SYSTICK_CTRL_CLKSOURCE | SYSTICK_CTRL_ENABLE);
  return 0U;
}

void SysTick_Delay_Ms(uint32_t ms) {
  uint32_t i = 0;
  for (i = 0; i < ms; ++i) {
    while ((SYSTICK->CTRL & SYSTICK_CTRL_COUNTFLAG) == 0U) {
      /* Polling, we wait until count reaches 0 */
    }
  }
}
