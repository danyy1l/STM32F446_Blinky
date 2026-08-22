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
 * First, I learn where the LED is on the board.
 * As said in the user manual, section 7.6:
 * User LD2: the green LED is a user LED connected to ARDUINO® signal D13
 * corresponding to STM32 I/O PA5 (pin 21)
 *
 * After, we need to do the following steps:
 * * Clock Enable for the port
 * * Setting initial state
 * * Defining direction (I/O)
 * * Configure output type (Push-Pull / Drain)
 * * Speed setting
 * * Pull-up or Pull-down
 *
 * Section 7.4 of RM0390 will give us all the needed information for this
 *
 * As a final comment, I am going to use the interface provided by the
 * manufacturer: stm32f446xx.h found in:
 * https://github.com/STMicroelectronics/STM32CubeF4/tree/master/Drivers/CMSIS/Include
 * https://github.com/STMicroelectronics/cmsis-device-f4/tree/a833f4af71410f25b01468f976560d7ff63a2fc9/Include
 */

typedef enum { VERY_SLOW = 0, SLOW, MEDIUM, FAST, TURBO } Blink_Speed;

int main(void) {
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable clock for PORT A
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

  GPIOA->MODER &= ~GPIO_MODER_MODE5; // Clear mode bits
  GPIOA->MODER |=
      GPIO_MODER_MODE5_0; // Activate bit 0, as 01 is output mode for moder
  GPIOA->OTYPER &= ~GPIO_OTYPER_OT5; // Ensure port is in push-pull state
                                     // instead of open drain
  GPIOA->OSPEEDR &=
      ~GPIO_OSPEEDER_OSPEEDR5; // Clear speed bits to set starting low speed

  GPIOC->MODER &= ~GPIO_MODER_MODE13;
  GPIOC->OTYPER &= ~GPIO_OTYPER_OT13;
  GPIOC->OSPEEDR &=
      ~GPIO_OSPEEDER_OSPEEDR13; // Clear speed bits to set starting low speed

  Blink_Speed current_speed = VERY_SLOW;
  volatile uint32_t count = 1000000U;
  volatile uint8_t button_pressed = 0;
  uint32_t ticks = 0;

  while (1) {
    if ((GPIOC->IDR & GPIO_IDR_ID13) == 0) {
      if (button_pressed == 0) {
        button_pressed = 1;

        ++current_speed;
        if (current_speed > TURBO)
          current_speed = VERY_SLOW;

        switch (current_speed) {
        case VERY_SLOW:
          count = 1000000U;
          break;
        case SLOW:
          count = 500000U;
          break;
        case MEDIUM:
          count = 250000U;
          break;
        case FAST:
          count = 125000U;
          break;
        case TURBO:
          count = 50000U;
          break;
        }
      }
    } else {
      button_pressed = 0;
    }

    ++ticks;
    if (ticks >= count) {
      GPIOA->ODR ^= GPIO_ODR_OD5;
      ticks = 0;
    }
  }

  return 0;
}
