#ifndef BSPLED_H
#define BSPLED_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @brief LED Board Service Package header file
 * * Contains the declarations, macros and structs needed for LED handling
 * 
 * @date 13-09-2026
 */

/**
 * @brief Initializes LED for usage
 * * Sets MCU registers for LED usage
 */
void LED_Init(void);

/**
 * @brief Toggles LED value
 * * Toggles GPIO ODR register corresponding to LED
 */
void LED_Toggle(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BSPLED_H */
