/**
 * @brief Hardware Abstraction Library for GPIO handling
 * * Contains GPIO abstraction implementations
 *
 * @author Danyyil Shykerynets
 * @file gpio.c
 * @date 13-09-2026
 */

#include "../Inc/gpio.h"
#include "../Inc/utils.h"

void GPIO_SetMode(GPIO_typedef *port, uint8_t pin, GPIO_Mode_t mode) {
  HW_ASSERT(port != (void *)0);
  HW_ASSERT(pin <= GPIO_PIN_MAX);

  uint32_t shift = pin * 2U;                // Each moder pin is 2 bits
  port->MODER &= ~(0x3UL << shift);         // Clear moder bits for given pin
  port->MODER |= ((uint32_t)mode << shift); // Set new mode
}

void GPIO_Write(GPIO_typedef *port, uint8_t pin, GPIO_PinState_t state) {
  HW_ASSERT(port != (void *)0);
  HW_ASSERT(pin <= GPIO_PIN_MAX);

  /* Here we use BSRR instead of ODR
   * BSRR is atomic, while ODR needs read-modify-write
   * As seen in RM0390, bits 0-15 set, while bits 16-31 clear
   */
  if (state == GPIO_PIN_SET) {
    port->BSRR = (1UL << pin);
  } else {
    port->BSRR = (1UL << (pin + 16U));
  }
}

void GPIO_Toggle(GPIO_typedef *port, uint8_t pin) {
  HW_ASSERT(port != (void *)0);
  HW_ASSERT(pin <= GPIO_PIN_MAX);

  port->ODR ^= (1UL << pin);
}

GPIO_PinState_t GPIO_Read(const GPIO_typedef *port, uint8_t pin) {
  HW_ASSERT(port != (void *)0);
  HW_ASSERT(pin <= GPIO_PIN_MAX);

  uint32_t mask = (1UL << pin);

  return ((port->IDR) & mask) ? GPIO_PIN_SET : GPIO_PIN_RESET;
}
