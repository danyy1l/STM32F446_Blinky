#ifndef SYSTICK_H
#define SYSTICK_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @brief SysTick header file
 * * Contains the declarations, macros and structs needed for SysTick config and usage
 * 
 * @date 13-09-2026
 */

#include <stdint.h>

#define SYSTICK_MAX_TICKS ((1UL << 24U) - 1U)

/**
 * @brief SysTick structure
 * * Contains SysTick's registers
 */
typedef struct {
  volatile uint32_t CTRL;       /**!< Control and Status register */
  volatile uint32_t LOAD;       /**!< Reload value register */
  volatile uint32_t VAL;        /**!< Current value register */
  volatile uint32_t CALIB;      /**!< Calibration register */
} SysTick_Typedef;

/* SysTick memory mapping */
#define SYSTICK_BASE 0xE000E010U

/* SysTick pointer definition */
#define SYSTICK ((SysTick_Typedef *)SYSTICK_BASE)

/***************************************/
/*            BIT DEFINITIONS          */
/***************************************/

/* Control and status register */
#define SYSTICK_CTRL_ENABLE_Pos           (0U)
#define SYSTICK_CTRL_ENABLE_Msk           (0x1UL << SYSTICK_CTRL_ENABLE_Pos)          /**!< 0x00000001 */
#define SYSTICK_CTRL_ENABLE               SYSTICK_CTRL_ENABLE_Msk

#define SYSTICK_CTRL_TICKINT_Pos          (1U)
#define SYSTICK_CTRL_TICKINT_Msk          (0x1UL << SYSTICK_CTRL_TICKINT_Pos)         /**!< 0x00000002 */
#define SYSTICK_CTRL_TICKINT              SYSTICK_CTRL_TICKINT_Msk

#define SYSTICK_CTRL_CLKSOURCE_Pos        (2U)
#define SYSTICK_CTRL_CLKSOURCE_Msk        (0x1UL << SYSTICK_CTRL_CLKSOURCE_Pos)       /**!< 0x00000004 */
#define SYSTICK_CTRL_CLKSOURCE            SYSTICK_CTRL_CLKSOURCE_Msk

#define SYSTICK_CTRL_COUNTFLAG_Pos        (16U)
#define SYSTICK_CTRL_COUNTFLAG_Msk        (0x1UL << SYSTICK_CTRL_COUNTFLAG_Pos)       /**!< 0x00010000 */
#define SYSTICK_CTRL_COUNTFLAG            SYSTICK_CTRL_COUNTFLAG_Msk

/* Reload value register */
#define SYSTICK_LOAD_RELOAD_Pos           (0U)
#define SYSTICK_LOAD_RELOAD_Msk           (0xFFFFFFUL << SYSTICK_LOAD_RELOAD_Pos)     /**!< 0x00FFFFFF */
#define SYSTICK_LOAD_RELOAD               SYSTICK_LOAD_RELOAD_Msk

/* Current value register */
#define SYSTICK_VAL_CURRENT_Pos           (0U)
#define SYSTICK_VAL_CURRENT_Msk           (0xFFFFFFUL << SYSTICK_VAL_CURRENT_Pos)     /**!< 0x00FFFFFF */
#define SYSTICK_VAL_CURRENT               SYSTICK_VAL_CURRENT_Msk

/* Calibration value register */
#define SYSTICK_CALIB_TENMS_Pos           (0U)
#define SYSTICK_CALIB_TENMS_Msk           (0xFFFFFFUL << SYSTICK_CALIB_TENMS_Pos)     /**!< 0x00FFFFFF */
#define SYSTICK_CALIB_TENMS               SYSTICK_CALIB_TENMS_Msk

#define SYSTICK_CALIB_SKEW_Pos            (30U)
#define SYSTICK_CALIB_SKEW_Msk            (0x1UL << SYSTICK_CALIB_SKEW_Pos)           /**!< 0x40000000 */
#define SYSTICK_CALIB_SKEW                SYSTICK_CALIB_SKEW_Msk

#define SYSTICK_CALIB_NOREF_Pos           (31U)
#define SYSTICK_CALIB_NOREF_Msk           (0x1UL << SYSTICK_CALIB_NOREF_Pos)          /**!< 0x80000000 */
#define SYSTICK_CALIB_NOREF               SYSTICK_CALIB_NOREF_Msk

/**
 * @brief Initializes systick
 * * Function created as per The Definitive Guide to ARM Cortex M3 and M4 processors.
 *
 * @param ticks Number of ticks to pass between interrupts
 */
uint32_t SysTick_Config(uint32_t ticks);

/**
 * @brief Delays the execution flow by polling
 * * This version will be adapted to poll instead of waiting for an interrupt
 *
 * @param ms Milliseconds to poll
 */
void SysTick_Delay_Ms(uint32_t ms);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SYSTICK_H */
