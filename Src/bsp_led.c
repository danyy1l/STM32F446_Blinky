/**
 * @brief LED BSP Implementation
 *
 * @author Danyyil Shykerynets
 * @file bsp_led.c
 * @date 13-09-2026
 */

#include "../Inc/bsp_led.h"
#include "../Inc/gpio.h"
#include "../Inc/rcc.h"

#define LED_PORT GPIOA
#define LED_PIN 5U

void LED_Init(void) {
  RCC_GPIO_ClockEnable(LED_PORT);
  GPIO_SetMode(LED_PORT, LED_PIN, GPIO_MODE_OUTPUT);
}

void LED_Toggle(void) { GPIO_Toggle(LED_PORT, LED_PIN); }
