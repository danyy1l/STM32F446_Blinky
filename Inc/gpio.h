#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @brief Hardware Abstraction Library for GPIO handling
 * * Contains main structs, macros and declarations for GPIO abstraction
 *
 * @author Danyyil Shykerynets
 * @file my_stm32f446xx.h
 * @date 10-09-2026
 */

#include "my_stm32f446xx.h"
#include <stdint.h>

#define GPIO_PIN_MAX 15U

/**
 * @brief Possible pin states
 * * Represents whether the pin is active or not
 */
typedef enum {
  GPIO_PIN_RESET = 0U,              /**!< Pin is connected to GND */
  GPIO_PIN_SET = 1U                 /**!< Pin is connected to VDD */
} GPIO_PinState_t;

/**
 * @brief Possible GPIO pin modes
 * * Used to set GPIO pin mode according to GPIO_MODER register
 */
typedef enum {
  GPIO_MODE_INPUT = 0b00U,          /**!< Input (reset state) */
  GPIO_MODE_OUTPUT = 0b01U,         /**!< General purpose output mode */
  GPIO_MODE_ALT_FUNCTION = 0b10U,   /**!< Alternate function mode */
  GPIO_MODE_ANALOG = 0b11U          /**!< Analog mode */ 
} GPIO_Mode_t;

/**
 * @brief Sets the specified mode to the indicated GPIO pin
 * * Modifies GPIO_MODER register
 *
 * @param port Port to which the pin belongs
 * @param pin Pin to which mode will be set
 * @param mode Mode in which the pin will be set
 */
void GPIO_SetMode(GPIO_typedef *port, uint8_t pin, GPIO_Mode_t mode);

/**
 * @brief Writes the state passed as parameter to the desired pin
 * * Modifies GPIO_BSRR register
 *
 * @param port Port to which the pin belongs
 * @param pin Pin to be written
 * @param state Value to write into the pin
 */
void GPIO_Write(GPIO_typedef *port, uint8_t pin, GPIO_PinState_t state);

/**
 * @brief Toggles the value of the desired pin
 *
 * @param port Port to which the pin belongs
 * @param pin Pin to be written
 */
void GPIO_Toggle(GPIO_typedef *port, uint8_t pin);

/**
 * @brief Reads the current value of a specified pin
 * * Reads GPIO_IDR register
 *
 * @param port Port to which the pin belongs
 * @param pin Pin to be read
 *
 * @return Current value of the indicated pin
 */
GPIO_PinState_t GPIO_Read(const GPIO_typedef *port, uint8_t pin);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* GPIO_H */
