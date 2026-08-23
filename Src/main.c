/**
 * @file main.c
 * @author Danyyil Shykerynets
 * @brief Main entry point
 * * Contains blinking and board setup logic
 * @version 1.0
 * @date 2026-08-19
 */

#include "../Inc/stm32f446xx.h"
#include <stdint.h>

/**
 * As a final comment, I am going to use the interface provided by the
 * manufacturer: stm32f446xx.h found in:
 * https://github.com/STMicroelectronics/STM32CubeF4/tree/master/Drivers/CMSIS/Include
 * https://github.com/STMicroelectronics/cmsis-device-f4/tree/a833f4af71410f25b01468f976560d7ff63a2fc9/Include
 */

static inline void delay(volatile uint32_t count) {
  while (count--) {
  }
}

int main(void) {
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable clock for PORT A

  GPIOA->MODER &= ~GPIO_MODER_MODE5; // Clear mode bits
  GPIOA->MODER |=
      GPIO_MODER_MODE5_0; // Activate bit 0, as 01 is output mode for moder
  GPIOA->OTYPER &= ~GPIO_OTYPER_OT5; // Ensure port is in push-pull state
                                     // instead of open drain
  GPIOA->OSPEEDR &=
      ~GPIO_OSPEEDER_OSPEEDR5; // Clear speed bits to set starting low speed

  while (1) {
    GPIOA->ODR ^= GPIO_ODR_OD5;

    delay(1000000U);
  }

  return 0;
}
