/**
 * @file main.c
 * @author Danyyil Shykerynets
 * @brief Main entry point
 * * Contains blinking and board setup logic
 * @version 1.0
 * @date 2026-08-19
 */

#include "../Inc/stm32f446xx.h"

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

int main(void) {
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable clock for PORT A
  GPIOA->ODR &= GPIO_ODR_OD5_Pos; // Assert that PIN5 begins in off state (0V)
}
