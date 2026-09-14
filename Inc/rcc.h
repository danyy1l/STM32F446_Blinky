#ifndef RCC_H
#define RCC_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @brief RCC HAL header file
 * * Contains the declarations, macros and structs needed for RCC abstraction
 * 
 * @date 12-09-2026
 */

#include "my_stm32f446xx.h"

/**
 * @brief Enables the clock for selected port
 * * Writes '1' in RCC_AHB1ENR register for specified port
 */
void RCC_GPIO_ClockEnable(const GPIO_typedef *port);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* RCC_H */
