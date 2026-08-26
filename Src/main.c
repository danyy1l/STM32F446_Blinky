/**
 * @file main.c
 * @author Danyyil Shykerynets
 * @brief Main entry point
 * * Contains blinking and board setup logic
 * Extended: The blinking rate is controlled by a button
 * @version 1.1
 * @date 2026-08-19
 */

#include "../Inc/my_stm32f446xx.h"
#include <stdint.h>

typedef enum { VERY_SLOW = 0, SLOW, MEDIUM, FAST, TURBO } Blink_Speed;

int main(void) {
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable clock for PORT A
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; // Enable clock for PORT C

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
