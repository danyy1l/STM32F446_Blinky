/**
 * @brief Hardware Abstraction Library for RCC Handling
 * * Contains RCC abstraction implementations
 *
 * @author Danyyil Shykerynets
 * @file rcc.c
 * @date 14-09-2026
 */

#include "../Inc/rcc.h"
#include "../Inc/utils.h"

void RCC_GPIO_ClockEnable(const GPIO_typedef *port) {
  HW_ASSERT(port != (void *)0);

  /* NOTE: Cannot use switch statements with a pointer as expression */
  if (port == GPIOA) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  } else if (port == GPIOB) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
  } else if (port == GPIOC) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
  } else if (port == GPIOD) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
  } else if (port == GPIOE) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
  } else if (port == GPIOF) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
  } else if (port == GPIOG) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
  } else if (port == GPIOH) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
  } else {
  }
}
