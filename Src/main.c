/**
 * @file main.c
 * @author Danyyil Shykerynets
 * @brief Main entry point
 * * Contains blinking and board setup logic
 * @version 1.2
 * @date 2026-09-14
 */

/* The HSI oscillator(default) is 16MHz */
#define SYSTEM_CORE_CLOCK 16000000U

#include "../Inc/bsp_led.h"
#include "../Inc/systick.h"
#include "../Inc/utils.h"

int main(void) {
  uint32_t systick_err = SysTick_Config(SYSTEM_CORE_CLOCK / 1000U);
  HW_ASSERT(systick_err == 0U);

  LED_Init();

  for (;;) {
    LED_Toggle();
    SysTick_Delay_Ms(500U);
  }

  return 0U;
}
