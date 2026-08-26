/**
 * @brief Main header file for custom stm32f446 HAL
 * * Contains only basic GPIO definitions for blinky
 *
 * @author Danyyil Shykerynets
 * @file my_stm32f446xx.h
 * @date 25-08-2026
 */

#include <stdint.h>

#define __I volatile const /**< Defines read permission */
#define __IO volatile      /**< Defines read / write permissions */
#define __O volatile       /**< Defines write permission */

#define PERIPH_BASE 0x40000000UL

#define APB1PERIPH_BASE PERIPH_BASE
#define APB2PERIPH_BASE (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE (PERIPH_BASE + 0x10000000UL)
#define AHB3PERIPH_BASE (PERIPH_BASE + 0x20000000UL)

typedef struct {
  __IO uint32_t CR;
  __IO uint32_t PLLCFGR;
  __IO uint32_t CFGR;
  __IO uint32_t CIR;
  __IO uint32_t AHB1RSTR;
  __IO uint32_t AHB2RSTR;
  __IO uint32_t AHB3RSTR;
  uint32_t RESERVED0;
  __IO uint32_t APB1RSTR;
  __IO uint32_t APB2RSTR;
  uint32_t RESERVED1[2];
  __IO uint32_t AHB1ENR;
  __IO uint32_t AHB2ENR;
  __IO uint32_t AHB3ENR;
  uint32_t RESERVED2;
  __IO uint32_t APB1ENR;
  __IO uint32_t APB2ENR;
  uint32_t RESERVED3[2];
  __IO uint32_t AHB1LPENR;
  __IO uint32_t AHB2LPENR;
  __IO uint32_t AHB3LPENR;
  uint32_t RESERVED4;
  __IO uint32_t APB1LPENR;
  __IO uint32_t APB2LPENR;
  uint32_t RESERVED5[2];
  __IO uint32_t BDCR;
  __IO uint32_t CSR;
  uint32_t RESERVED6[2];
  __IO uint32_t SSCGR;
  __IO uint32_t RRC_PLLI2SCFGR;
  __IO uint32_t RRC_PLLSAICFGR;
  __IO uint32_t DCKCFGR;
  __IO uint32_t CKGATENR;
  __IO uint32_t DCKCFGR2;
} RCC_typedef;

typedef struct {
  __IO uint32_t MODER;
  __IO uint32_t OTYPER;
  __IO uint32_t OSPEEDR;
  __IO uint32_t PUPDR;
  __I uint32_t IDR;
  __IO uint32_t ODR;
  __O uint32_t BSRR;
  __IO uint32_t LCKR;
  __IO uint32_t AFRL;
  __IO uint32_t AFRH;
} GPIO_typedef;

#define RCC_BASE (AHB1PERIPH_BASE + 0x00003800UL)

#define GPIOA_BASE (AHB1PERIPH_BASE)
#define GPIOB_BASE (AHB1PERIPH_BASE + 0x00000400UL)
#define GPIOC_BASE (AHB1PERIPH_BASE + 0x00000800UL)
#define GPIOD_BASE (AHB1PERIPH_BASE + 0x00000C00UL)
#define GPIOE_BASE (AHB1PERIPH_BASE + 0x00001000UL)
#define GPIOF_BASE (AHB1PERIPH_BASE + 0x00001400UL)
#define GPIOG_BASE (AHB1PERIPH_BASE + 0x00001800UL)
#define GPIOH_BASE (AHB1PERIPH_BASE + 0x00001C00UL)

#define GPIOA (GPIO_typedef *)GPIOA_BASE
#define GPIOB (GPIO_typedef *)GPIOB_BASE
#define GPIOC (GPIO_typedef *)GPIOC_BASE
#define GPIOD (GPIO_typedef *)GPIOD_BASE
#define GPIOE (GPIO_typedef *)GPIOE_BASE
#define GPIOF (GPIO_typedef *)GPIOF_BASE
#define GPIOG (GPIO_typedef *)GPIOG_BASE
#define GPIOH (GPIO_typedef *)GPIOH_BASE

#define RCC (RCC_typedef *)RCC_BASE

void GPIO_write_pin();
void GPIO_reset();
