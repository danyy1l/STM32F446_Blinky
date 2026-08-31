#ifndef __MYSTM32F446xx_H_
#define __MYSTM32F446xx_H_

#ifdef __cplusplus
extern "C"  {
#endif /* __cplusplus */

/**
 * @brief Main header file for custom stm32f446 HAL
 * * Contains only basic GPIO definitions for blinky
 *
 * @author Danyyil Shykerynets
 * @file my_stm32f446xx.h
 * @date 25-08-2026
 */

#include <stdint.h>

/***************************************************************/
/*                    GENERAL USE DECLARATIONS                 */
/***************************************************************/

/**< Read/Write permission macros (Mostly indicative) */
#define __I volatile const /**< Defines read permission */
#define __IO volatile      /**< Defines read / write permissions */
#define __O volatile       /**< Defines write permission */

/***************************************************************/
/*                       PERIPHERAL STRUCTS                    */
/***************************************************************/

/**< RCC struct declaration */
typedef struct {
  __IO uint32_t CR;             /**< Clock control register */
  __IO uint32_t PLLCFGR;        /**< PLL configuration register */
  __IO uint32_t CFGR;           /**< Clock configuration register */
  __IO uint32_t CIR;            /**< Clock interrupt register */
  __IO uint32_t AHB1RSTR;       /**< AHB1 peripheral reset register */
  __IO uint32_t AHB2RSTR;       /**< AHB2 peripheral reset register */
  __IO uint32_t AHB3RSTR;       /**< AHB3 peripheral reset register */
  uint32_t RESERVED0;
  __IO uint32_t APB1RSTR;       /**< APB1 peripheral reset register */
  __IO uint32_t APB2RSTR;       /**< APB2 peripheral reset register */
  uint32_t RESERVED1[2];
  __IO uint32_t AHB1ENR;        /**< AHB1 peripheral clock enable register */
  __IO uint32_t AHB2ENR;        /**< AHB2 peripheral clock enable register */
  __IO uint32_t AHB3ENR;        /**< AHB3 peripheral clock enable register */
  uint32_t RESERVED2;           
  __IO uint32_t APB1ENR;        /**< APB1 peripheral clock enable register */
  __IO uint32_t APB2ENR;        /**< APB2 peripheral clock enable register */
  uint32_t RESERVED3[2];        
  __IO uint32_t AHB1LPENR;      /**< AHB1 peripheral clock enable in low power mode register */
  __IO uint32_t AHB2LPENR;      /**< AHB2 peripheral clock enable in low power mode register */
  __IO uint32_t AHB3LPENR;      /**< AHB3 peripheral clock enable in low power mode register */
  uint32_t RESERVED4;           
  __IO uint32_t APB1LPENR;      /**< APB1 peripheral clock enable in low power mode register */
  __IO uint32_t APB2LPENR;      /**< APB2 peripheral clock enable in low power mode register */
  uint32_t RESERVED5[2];        
  __IO uint32_t BDCR;           /**< Backup domain control register */
  __IO uint32_t CSR;            /**< Clock control and status register */
  uint32_t RESERVED6[2];
  __IO uint32_t SSCGR;          /**< Spread spectrum clock generation register */
  __IO uint32_t PLLI2SCFGR;     /**< PLLI2S configuration register */
  __IO uint32_t PLLSAICFGR;     /**< PLLSAI configuration register */
  __IO uint32_t DCKCFGR;        /**< Dedicated clock configuration register */
  __IO uint32_t CKGATENR;       /**< Clocks gated enable register */
  __IO uint32_t DCKCFGR2;       /**< Dedicated clocks configuration register 2 */
} RCC_typedef;

/**< GPIO struct template */
typedef struct {
  __IO uint32_t MODER;   /**< Port mode register */
  __IO uint32_t OTYPER;  /**< Port output type register */
  __IO uint32_t OSPEEDR; /**< Port output speed register */
  __IO uint32_t PUPDR;   /**< Port pull-up/Pull-down register */
  __I uint32_t IDR;      /**< Port input data register */
  __IO uint32_t ODR;     /**< Port output data register */
  __O uint32_t BSRR;     /**< Port bit set/reset register */
  __IO uint32_t LCKR;    /**< Port configuration lock register */
  __IO uint32_t AFRL;    /**< Alternate function low register */
  __IO uint32_t AFRH;    /**< Alternate function high register */
} GPIO_typedef;

/***************************************************************/
/*                          MEMORY MAP                         */
/***************************************************************/

#define PERIPH_BASE 0x40000000UL /**< Peripheral base region in the alias region */

/**< Peripheral memory map */
#define APB1PERIPH_BASE PERIPH_BASE
#define APB2PERIPH_BASE (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE (PERIPH_BASE + 0x10000000UL)
#define AHB3PERIPH_BASE (PERIPH_BASE + 0x20000000UL)

/**< RCC memory mapping macro */
#define RCC_BASE (AHB1PERIPH_BASE + 0x00003800UL)

/**< GPIO ports memory mapping */
#define GPIOA_BASE (AHB1PERIPH_BASE)
#define GPIOB_BASE (AHB1PERIPH_BASE + 0x00000400UL)
#define GPIOC_BASE (AHB1PERIPH_BASE + 0x00000800UL)
#define GPIOD_BASE (AHB1PERIPH_BASE + 0x00000C00UL)
#define GPIOE_BASE (AHB1PERIPH_BASE + 0x00001000UL)
#define GPIOF_BASE (AHB1PERIPH_BASE + 0x00001400UL)
#define GPIOG_BASE (AHB1PERIPH_BASE + 0x00001800UL)
#define GPIOH_BASE (AHB1PERIPH_BASE + 0x00001C00UL)

/***************************************************************/
/*                    POINTER TO MACRO CASTING                 */
/***************************************************************/

/**< RCC pointer casting */
#define RCC ((RCC_typedef *)RCC_BASE)

/**< GPIO pointer casting */
#define GPIOA ((GPIO_typedef *)GPIOA_BASE)
#define GPIOB ((GPIO_typedef *)GPIOB_BASE)
#define GPIOC ((GPIO_typedef *)GPIOC_BASE)
#define GPIOD ((GPIO_typedef *)GPIOD_BASE)
#define GPIOE ((GPIO_typedef *)GPIOE_BASE)
#define GPIOF ((GPIO_typedef *)GPIOF_BASE)
#define GPIOG ((GPIO_typedef *)GPIOG_BASE)
#define GPIOH ((GPIO_typedef *)GPIOH_BASE)


/**********************************************************/
/*                 REGISTER BIT DEFINITIONS              */
/**********************************************************/

/* ------------------------- RCC ------------------------ */

/* RCC clock control register */
#define RCC_CR_HSION_Pos                (0U)
#define RCC_CR_HSION_Msk                (0x1UL << RCC_CR_HSION_Pos)               /*!< 0x00000001 */
#define RCC_CR_HSION                    RCC_CR_HSION_Msk

#define RCC_CR_HSIRDY_Pos               (1U)
#define RCC_CR_HSIRDY_Msk               (0x1UL << RCC_CR_HSIRDY_Pos)              /*!< 0x00000002 */
#define RCC_CR_HSIRDY                   RCC_CR_HSIRDY_Msk

#define RCC_CR_HSITRIM_Pos              (3U)
#define RCC_CR_HSITRIM_Msk              (0x1FUL << RCC_CR_HSITRIM_Pos)            /*!< 0x000000F8 */
#define RCC_CR_HSITRIM                  RCC_CR_HSITRIM_Msk
#define RCC_CR_HSITRIM_0                (0x1UL << RCC_CR_HSITRIM_Pos)             /*!< 0x00000008 */
#define RCC_CR_HSITRIM_1                (0x2UL << RCC_CR_HSITRIM_Pos)             /*!< 0x00000010 */
#define RCC_CR_HSITRIM_2                (0x4UL << RCC_CR_HSITRIM_Pos)             /*!< 0x00000020 */
#define RCC_CR_HSITRIM_3                (0x8UL << RCC_CR_HSITRIM_Pos)             /*!< 0x00000040 */
#define RCC_CR_HSITRIM_4                (0x10UL << RCC_CR_HSITRIM_Pos)            /*!< 0x00000080 */

#define RCC_CR_HSICAL_Pos               (8U)
#define RCC_CR_HSICAL_Msk               (0xFFUL << RCC_CR_HSICAL_Pos)             /*!< 0x0000FF00 */
#define RCC_CR_HSICAL                   RCC_CR_HSICAL_Msk
#define RCC_CR_HSICAL_0                 (0x1UL << RCC_CR_HSICAL_Pos)              /*!< 0x00000100 */
#define RCC_CR_HSICAL_1                 (0x2UL << RCC_CR_HSICAL_Pos)              /*!< 0x00000200 */
#define RCC_CR_HSICAL_2                 (0x4UL << RCC_CR_HSICAL_Pos)              /*!< 0x00000400 */
#define RCC_CR_HSICAL_3                 (0x8UL << RCC_CR_HSICAL_Pos)              /*!< 0x00000800 */
#define RCC_CR_HSICAL_4                 (0x10UL << RCC_CR_HSICAL_Pos)             /*!< 0x00001000 */
#define RCC_CR_HSICAL_5                 (0x20UL << RCC_CR_HSICAL_Pos)             /*!< 0x00002000 */

#define RCC_CR_HSICAL_6                 (0x40UL << RCC_CR_HSICAL_Pos)             /*!< 0x00004000 */
#define RCC_CR_HSICAL_7                 (0x80UL << RCC_CR_HSICAL_Pos)             /*!< 0x00008000 */

#define RCC_CR_HSEON_Pos                (16U)
#define RCC_CR_HSEON_Msk                (0x1UL << RCC_CR_HSEON_Pos)               /*!< 0x00010000 */
#define RCC_CR_HSEON                    RCC_CR_HSEON_Msk

#define RCC_CR_HSERDY_Pos               (17U)
#define RCC_CR_HSERDY_Msk               (0x1UL << RCC_CR_HSERDY_Pos)              /*!< 0x00020000 */
#define RCC_CR_HSERDY                   RCC_CR_HSERDY_Msk

#define RCC_CR_HSEBYP_Pos               (18U)
#define RCC_CR_HSEBYP_Msk               (0x1UL << RCC_CR_HSEBYP_Pos)              /*!< 0x00040000 */
#define RCC_CR_HSEBYP                   RCC_CR_HSEBYP_Msk

#define RCC_CR_CSSON_Pos                (19U)
#define RCC_CR_CSSON_Msk                (0x1UL << RCC_CR_CSSON_Pos)               /*!< 0x00080000 */
#define RCC_CR_CSSON                    RCC_CR_CSSON_Msk

#define RCC_CR_PLLON_Pos                (24U)
#define RCC_CR_PLLON_Msk                (0x1UL << RCC_CR_PLLON_Pos)               /*!< 0x01000000 */
#define RCC_CR_PLLON                    RCC_CR_PLLON_Msk

#define RCC_CR_PLLRDY_Pos               (25U)
#define RCC_CR_PLLRDY_Msk               (0x1UL << RCC_CR_PLLRDY_Pos)              /*!< 0x02000000 */
#define RCC_CR_PLLRDY                   RCC_CR_PLLRDY_Msk

#define RCC_CR_PLLI2SON_Pos             (26U)
#define RCC_CR_PLLI2SON_Msk             (0x1UL << RCC_CR_PLLI2SON_Pos)            /*!< 0x04000000 */
#define RCC_CR_PLLI2SON                 RCC_CR_PLLI2SON_Msk

#define RCC_CR_PLLI2SRDY_Pos            (27U)
#define RCC_CR_PLLI2SRDY_Msk            (0x1UL << RCC_CR_PLLI2SRDY_Pos)           /*!< 0x08000000 */
#define RCC_CR_PLLI2SRDY                RCC_CR_PLLI2SRDY_Msk

#define RCC_CR_PLLSAION_Pos             (28U)
#define RCC_CR_PLLSAION_Msk             (0x1UL << RCC_CR_PLLSAION_Pos)            /*!< 0x10000000 */
#define RCC_CR_PLLSAION                 RCC_CR_PLLSAION_Msk

#define RCC_CR_PLLSAIRDY_Pos            (29U)
#define RCC_CR_PLLSAIRDY_Msk            (0x1UL << RCC_CR_PLLSAIRDY_Pos)           /*!< 0x20000000 */
#define RCC_CR_PLLSAIRDY                RCC_CR_PLLSAIRDY_Msk

/* RCC PLL configuration register */

#define RCC_PLLCFGR_PLLM_Pos            (0U)
#define RCC_PLLCFGR_PLLM_Msk            (0x3FUL << RCC_PLLCFGR_PLLM_Pos)          /*!< 0x0000003F */
#define RCC_PLLCFGR_PLLM                RCC_PLLCFGR_PLLM_Msk
#define RCC_PLLCFGR_PLLM_0              (0x1UL << RCC_PLLCFGR_PLLM_Pos)           /*!< 0x00000001 */
#define RCC_PLLCFGR_PLLM_1              (0x2UL << RCC_PLLCFGR_PLLM_Pos)           /*!< 0x00000002 */
#define RCC_PLLCFGR_PLLM_2              (0x4UL << RCC_PLLCFGR_PLLM_Pos)           /*!< 0x00000004 */
#define RCC_PLLCFGR_PLLM_3              (0x8UL << RCC_PLLCFGR_PLLM_Pos)           /*!< 0x00000008 */
#define RCC_PLLCFGR_PLLM_4              (0x10UL << RCC_PLLCFGR_PLLM_Pos)          /*!< 0x00000010 */
#define RCC_PLLCFGR_PLLM_5              (0x20UL << RCC_PLLCFGR_PLLM_Pos)          /*!< 0x00000020 */
#define RCC_PLLCFGR_PLLM_6              (0x40UL << RCC_PLLCFGR_PLLM_Pos)          /*!< 0x00000040 */

#define RCC_PLLCFGR_PLLN_Pos            (6U)
#define RCC_PLLCFGR_PLLN_Msk            (0x1FFUL << RCC_PLLCFGR_PLLN_Pos)         /*!< 0x00007FC0 */
#define RCC_PLLCFGR_PLLN                RCC_PLLCFGR_PLLN_Msk
#define RCC_PLLCFGR_PLLN_0              (0x1UL << RCC_PLLCFGR_PLLN_Pos)           /*!< 0x00000040 */
#define RCC_PLLCFGR_PLLN_1              (0x2UL << RCC_PLLCFGR_PLLN_Pos)           /*!< 0x00000080 */
#define RCC_PLLCFGR_PLLN_2              (0x4UL << RCC_PLLCFGR_PLLN_Pos)           /*!< 0x00000100 */
#define RCC_PLLCFGR_PLLN_3              (0x8UL << RCC_PLLCFGR_PLLN_Pos)           /*!< 0x00000200 */
#define RCC_PLLCFGR_PLLN_4              (0x10UL << RCC_PLLCFGR_PLLN_Pos)          /*!< 0x00000400 */
#define RCC_PLLCFGR_PLLN_5              (0x20UL << RCC_PLLCFGR_PLLN_Pos)          /*!< 0x00000800 */
#define RCC_PLLCFGR_PLLN_6              (0x40UL << RCC_PLLCFGR_PLLN_Pos)          /*!< 0x00001000 */
#define RCC_PLLCFGR_PLLN_7              (0x80UL << RCC_PLLCFGR_PLLN_Pos)          /*!< 0x00002000 */
#define RCC_PLLCFGR_PLLN_8              (0x100UL << RCC_PLLCFGR_PLLN_Pos)         /*!< 0x00004000 */

#define RCC_PLLCFGR_PLLP_Pos            (16U)
#define RCC_PLLCFGR_PLLP_Msk            (0x3UL << RCC_PLLCFGR_PLLP_Pos)           /*!< 0x00030000 */
#define RCC_PLLCFGR_PLLP                RCC_PLLCFGR_PLLP_Msk
#define RCC_PLLCFGR_PLLP_0              (0x1UL << RCC_PLLCFGR_PLLP_Pos)           /*!< 0x00010000 */
#define RCC_PLLCFGR_PLLP_1              (0x2UL << RCC_PLLCFGR_PLLP_Pos)           /*!< 0x00020000 */

#define RCC_PLLCFGR_PLLSRC_Pos          (22U)
#define RCC_PLLCFGR_PLLSRC_Msk          (0x1UL << RCC_PLLCFGR_PLLSRC_Pos)         /*!< 0x00400000 */
#define RCC_PLLCFGR_PLLSRC              RCC_PLLCFGR_PLLSRC_Msk
#define RCC_PLLCFGR_PLLSRC_HSE_Pos      (22U)
#define RCC_PLLCFGR_PLLSRC_HSE_Msk      (0x1UL << RCC_PLLCFGR_PLLSRC_HSE_Pos)     /*!< 0x00400000 */
#define RCC_PLLCFGR_PLLSRC_HSE          RCC_PLLCFGR_PLLSRC_HSE_Msk
#define RCC_PLLCFGR_PLLSRC_HSI          0x00000000U

#define RCC_PLLCFGR_PLLQ_Pos            (24U)
#define RCC_PLLCFGR_PLLQ_Msk            (0xFUL << RCC_PLLCFGR_PLLQ_Pos)           /*!< 0x0F000000 */
#define RCC_PLLCFGR_PLLQ                RCC_PLLCFGR_PLLQ_Msk
#define RCC_PLLCFGR_PLLQ_0              (0x1UL << RCC_PLLCFGR_PLLQ_Pos)           /*!< 0x01000000 */
#define RCC_PLLCFGR_PLLQ_1              (0x2UL << RCC_PLLCFGR_PLLQ_Pos)           /*!< 0x02000000 */
#define RCC_PLLCFGR_PLLQ_2              (0x4UL << RCC_PLLCFGR_PLLQ_Pos)           /*!< 0x04000000 */
#define RCC_PLLCFGR_PLLQ_3              (0x8UL << RCC_PLLCFGR_PLLQ_Pos)           /*!< 0x08000000 */

#define RCC_PLLCFGR_PLLR_Pos            (28U)
#define RCC_PLLCFGR_PLLR_Msk            (0x7UL << RCC_PLLCFGR_PLLR_Pos)           /*!< 0x70000000 */
#define RCC_PLLCFGR_PLLR                RCC_PLLCFGR_PLLR_Msk
#define RCC_PLLCFGR_PLLR_0              (0x1UL << RCC_PLLCFGR_PLLR_Pos)           /*!< 0x10000000 */
#define RCC_PLLCFGR_PLLR_1              (0x2UL << RCC_PLLCFGR_PLLR_Pos)           /*!< 0x20000000 */
#define RCC_PLLCFGR_PLLR_2              (0x4UL << RCC_PLLCFGR_PLLR_Pos)           /*!< 0x40000000 */

/* RCC clock configuration register */
/* System clock switch config */
#define RCC_CFGR_SW_Pos                 (0U)
#define RCC_CFGR_SW_Msk                 (0x3UL << RCC_CFGR_SW_Pos)                /*!< 0x00000003 */
#define RCC_CFGR_SW                     RCC_CFGR_SW_Msk
#define RCC_CFGR_SW_0                   (0x1UL << RCC_CFGR_SW_Pos)                /*!< 0x00000001 */
#define RCC_CFGR_SW_1                   (0x2UL << RCC_CFGR_SW_Pos)                /*!< 0x00000002 */

#define RCC_CFGR_SW_HSI                 (0x00UL << RCC_CFGR_SW_Pos)               /*!< HSI oscillator selected as sys clock */
#define RCC_CFGR_SW_HSE                 (0x01UL << RCC_CFGR_SW_Pos)               /*!< HSE oscillator selected as sys clock */
#define RCC_CFGR_SW_PLL_P               (0x02UL << RCC_CFGR_SW_Pos)               /*!< PLL_P oscillator selected as sys clock */
#define RCC_CFGR_SW_PLL_R               (0x03UL << RCC_CFGR_SW_Pos)               /*!< PLL_R oscillator selected as sys clock */

/* System clock switch status config */
#define RCC_CFGR_SWS_Pos                (2U)
#define RCC_CFGR_SWS_Msk                (0x3UL << RCC_CFGR_SWS_Pos)               /*!< 0x0000000C */
#define RCC_CFGR_SWS                    RCC_CFGR_SWS_Msk
#define RCC_CFGR_SWS_0                  (0x1UL << RCC_CFGR_SWS_Pos)               /*!< 0x00000004 */
#define RCC_CFGR_SWS_1                  (0x2UL << RCC_CFGR_SWS_Pos)               /*!< 0x00000008 */

#define RCC_CFGR_SWS_HSI                (0x00UL << RCC_CFGR_SWS_Pos)              /*!< HSI oscillator used as the system clock */         
#define RCC_CFGR_SWS_HSE                (0x01UL << RCC_CFGR_SWS_Pos)              /*!< HSE oscillator used as the system clock */
#define RCC_CFGR_SWS_PLL                (0x02UL << RCC_CFGR_SWS_Pos)              /*!< PLL_P used as the system clock */
#define RCC_CFGR_SWS_PLL_R              (0x03UL << RCC_CFGR_SWS_Pos)              /*!< PLL_R used as the system clock */

/* AHB prescaler config */
#define RCC_CFGR_HPRE_Pos               (4U)
#define RCC_CFGR_HPRE_Msk               (0xFUL << RCC_CFGR_HPRE_Pos)              /*!< 0x000000F0 */
#define RCC_CFGR_HPRE                   RCC_CFGR_HPRE_Msk
#define RCC_CFGR_HPRE_0                 (0x1UL << RCC_CFGR_HPRE_Pos)              /*!< 0x00000010 */
#define RCC_CFGR_HPRE_1                 (0x2UL << RCC_CFGR_HPRE_Pos)              /*!< 0x00000020 */
#define RCC_CFGR_HPRE_2                 (0x4UL << RCC_CFGR_HPRE_Pos)              /*!< 0x00000040 */
#define RCC_CFGR_HPRE_3                 (0x8UL << RCC_CFGR_HPRE_Pos)              /*!< 0x00000080 */

#define RCC_CFGR_HPRE_DIV1              (0x0UL << RCC_CFGR_HPRE_Pos)              /*!< SYSCLK not divided */
#define RCC_CFGR_HPRE_DIV2              (0x8UL << RCC_CFGR_HPRE_Pos)              /*!< SYSCLK divided by 2 */
#define RCC_CFGR_HPRE_DIV4              (0x9UL << RCC_CFGR_HPRE_Pos)              /*!< SYSCLK divided by 4 */
#define RCC_CFGR_HPRE_DIV8              (0xAUL << RCC_CFGR_HPRE_Pos)              /*!< SYSCLK divided by 8 */
#define RCC_CFGR_HPRE_DIV16             (0xBUL << RCC_CFGR_HPRE_Pos)              /*!< SYSCLK divided by 16 */
#define RCC_CFGR_HPRE_DIV64             (0xCUL << RCC_CFGR_HPRE_Pos)              /*!< SYSCLK divided by 64 */
#define RCC_CFGR_HPRE_DIV128            (0xDUL << RCC_CFGR_HPRE_Pos)              /*!< SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256            (0xEUL << RCC_CFGR_HPRE_Pos)              /*!< SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512            (0xFUL << RCC_CFGR_HPRE_Pos)              /*!< SYSCLK divided by 512 */

/* APB low speed prescaler config (APB1)*/
#define RCC_CFGR_PPRE1_Pos              (10U)
#define RCC_CFGR_PPRE1_Msk              (0x7UL << RCC_CFGR_PPRE1_Pos)             /*!< 0x00001C00 */
#define RCC_CFGR_PPRE1                  RCC_CFGR_PPRE1_Msk
#define RCC_CFGR_PPRE1_0                (0x1UL << RCC_CFGR_PPRE1_Pos)             /*!< 0x00000400 */
#define RCC_CFGR_PPRE1_1                (0x2UL << RCC_CFGR_PPRE1_Pos)             /*!< 0x00000800 */
#define RCC_CFGR_PPRE1_2                (0x4UL << RCC_CFGR_PPRE1_Pos)             /*!< 0x00001000 */

#define RCC_CFGR_PPRE1_DIV1             (0x0UL << RCC_CFGR_PPRE1_Pos)             /*!< HCLK divided by 1 */
#define RCC_CFGR_PPRE1_DIV2             (0x4UL << RCC_CFGR_PPRE1_Pos)             /*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE1_DIV4             (0x5UL << RCC_CFGR_PPRE1_Pos)             /*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE1_DIV8             (0x6UL << RCC_CFGR_PPRE1_Pos)             /*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE1_DIV16            (0x7UL << RCC_CFGR_PPRE1_Pos)             /*!< HCLK divided by 16 */

/* APB high speed prescaler config (APB2 */
#define RCC_CFGR_PPRE2_Pos              (13U)
#define RCC_CFGR_PPRE2_Msk              (0x7UL << RCC_CFGR_PPRE2_Pos)             /*!< 0x0000E000 */
#define RCC_CFGR_PPRE2                  RCC_CFGR_PPRE2_Msk
#define RCC_CFGR_PPRE2_0                (0x1UL << RCC_CFGR_PPRE2_Pos)             /*!< 0x00002000 */
#define RCC_CFGR_PPRE2_1                (0x2UL << RCC_CFGR_PPRE2_Pos)             /*!< 0x00004000 */
#define RCC_CFGR_PPRE2_2                (0x4UL << RCC_CFGR_PPRE2_Pos)             /*!< 0x00008000 */

#define RCC_CFGR_PPRE2_DIV1             (0x0UL << RCC_CFGR_PPRE2_Pos)             /*!< HCLK divided by 1 */
#define RCC_CFGR_PPRE2_DIV2             (0x4UL << RCC_CFGR_PPRE2_Pos)             /*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE2_DIV4             (0x5UL << RCC_CFGR_PPRE2_Pos)             /*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE2_DIV8             (0x6UL << RCC_CFGR_PPRE2_Pos)             /*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE2_DIV16            (0x7UL << RCC_CFGR_PPRE2_Pos)             /*!< HCLK divided by 16 */

/* HSE division factor for RTC Clock conig */
#define RCC_CFGR_RTCPRE_Pos             (16U)
#define RCC_CFGR_RTCPRE_Msk             (0x1FUL << RCC_CFGR_RTCPRE_Pos)           /*!< 0x001F0000 */
#define RCC_CFGR_RTCPRE                 RCC_CFGR_RTCPRE_Msk
#define RCC_CFGR_RTCPRE_0               (0x1UL << RCC_CFGR_RTCPRE_Pos)            /*!< 0x00010000 */
#define RCC_CFGR_RTCPRE_1               (0x2UL << RCC_CFGR_RTCPRE_Pos)            /*!< 0x00020000 */
#define RCC_CFGR_RTCPRE_2               (0x4UL << RCC_CFGR_RTCPRE_Pos)            /*!< 0x00040000 */
#define RCC_CFGR_RTCPRE_3               (0x8UL << RCC_CFGR_RTCPRE_Pos)            /*!< 0x00080000 */
#define RCC_CFGR_RTCPRE_4               (0x10UL << RCC_CFGR_RTCPRE_Pos)           /*!< 0x00100000 */

/* Microcontroller clock output 1 */
#define RCC_CFGR_MCO1_Pos               (21U)
#define RCC_CFGR_MCO1_Msk               (0x3UL << RCC_CFGR_MCO1_Pos)              /*!< 0x00600000 */
#define RCC_CFGR_MCO1                   RCC_CFGR_MCO1_Msk
#define RCC_CFGR_MCO1_0                 (0x1UL << RCC_CFGR_MCO1_Pos)              /*!< 0x00200000 */
#define RCC_CFGR_MCO1_1                 (0x2UL << RCC_CFGR_MCO1_Pos)              /*!< 0x00400000 */

#define RCC_CFGR_MCO1_HSI               (0x0UL << RCC_CFGR_MCO1_Pos)              /*!< HSI clock selected */
#define RCC_CFGR_MCO1_LSE               (0x1UL << RCC_CFGR_MCO1_Pos)              /*!< LSE oscillator clock selected */
#define RCC_CFGR_MCO1_HSE               (0x2UL << RCC_CFGR_MCO1_Pos)              /*!< HSE oscillator clock selected */
#define RCC_CFGR_MCO1_PLL               (0x3UL << RCC_CFGR_MCO1_Pos)              /*!< PLL clock selected */

/* MCO1 prescaler config */
#define RCC_CFGR_MCO1PRE_Pos            (24U)
#define RCC_CFGR_MCO1PRE_Msk            (0x7UL << RCC_CFGR_MCO1PRE_Pos)           /*!< 0x07000000 */
#define RCC_CFGR_MCO1PRE                RCC_CFGR_MCO1PRE_Msk
#define RCC_CFGR_MCO1PRE_0              (0x1UL << RCC_CFGR_MCO1PRE_Pos)           /*!< 0x01000000 */
#define RCC_CFGR_MCO1PRE_1              (0x2UL << RCC_CFGR_MCO1PRE_Pos)           /*!< 0x02000000 */
#define RCC_CFGR_MCO1PRE_2              (0x4UL << RCC_CFGR_MCO1PRE_Pos)           /*!< 0x04000000 */

#define RCC_CFGR_MCO1PRE_DIV1           (0x0UL << RCC_CFGR_MCO1PRE_Pos)           /*!< No division */
#define RCC_CFGR_MCO1PRE_DIV2           (0x4UL << RCC_CFGR_MCO1PRE_Pos)           /*!< Division by 2 */
#define RCC_CFGR_MCO1PRE_DIV3           (0x5UL << RCC_CFGR_MCO1PRE_Pos)           /*!< Division by 3 */
#define RCC_CFGR_MCO1PRE_DIV4           (0x6UL << RCC_CFGR_MCO1PRE_Pos)           /*!< Division by 4 */
#define RCC_CFGR_MCO1PRE_DIV5           (0x7UL << RCC_CFGR_MCO1PRE_Pos)           /*!< Division by 5 */

/* MCO2 prescaler config */
#define RCC_CFGR_MCO2PRE_Pos            (27U)
#define RCC_CFGR_MCO2PRE_Msk            (0x7UL << RCC_CFGR_MCO2PRE_Pos)           /*!< 0x38000000 */
#define RCC_CFGR_MCO2PRE                RCC_CFGR_MCO2PRE_Msk
#define RCC_CFGR_MCO2PRE_0              (0x1UL << RCC_CFGR_MCO2PRE_Pos)           /*!< 0x08000000 */
#define RCC_CFGR_MCO2PRE_1              (0x2UL << RCC_CFGR_MCO2PRE_Pos)           /*!< 0x10000000 */
#define RCC_CFGR_MCO2PRE_2              (0x4UL << RCC_CFGR_MCO2PRE_Pos)           /*!< 0x20000000 */

#define RCC_CFGR_MCO2PRE_DIV1           (0x0UL << RCC_CFGR_MCO2PRE_Pos)           /*!< No division */
#define RCC_CFGR_MCO2PRE_DIV2           (0x4UL << RCC_CFGR_MCO2PRE_Pos)           /*!< Division by 2 */
#define RCC_CFGR_MCO2PRE_DIV3           (0x5UL << RCC_CFGR_MCO2PRE_Pos)           /*!< Division by 3 */
#define RCC_CFGR_MCO2PRE_DIV4           (0x6UL << RCC_CFGR_MCO2PRE_Pos)           /*!< Division by 4 */
#define RCC_CFGR_MCO2PRE_DIV5           (0x7UL << RCC_CFGR_MCO2PRE_Pos)           /*!< Division by 5 */

/* Microcontroller clock output 2 */
#define RCC_CFGR_MCO2_Pos               (30U)
#define RCC_CFGR_MCO2_Msk               (0x3UL << RCC_CFGR_MCO2_Pos)              /*!< 0xC0000000 */
#define RCC_CFGR_MCO2                   RCC_CFGR_MCO2_Msk
#define RCC_CFGR_MCO2_0                 (0x1UL << RCC_CFGR_MCO2_Pos)              /*!< 0x40000000 */
#define RCC_CFGR_MCO2_1                 (0x2UL << RCC_CFGR_MCO2_Pos)              /*!< 0x80000000 */

#define RCC_CFGR_MCO2_HSI               (0x0UL << RCC_CFGR_MCO2_Pos)              /*!< SYSCLK selected */
#define RCC_CFGR_MCO2_LSE               (0x1UL << RCC_CFGR_MCO2_Pos)              /*!< PLLI2S clock selected */
#define RCC_CFGR_MCO2_HSE               (0x2UL << RCC_CFGR_MCO2_Pos)              /*!< HSE oscillator clock selected */
#define RCC_CFGR_MCO2_PLL               (0x3UL << RCC_CFGR_MCO2_Pos)              /*!< PLL clock selected */

/* RCC Clock interrupt register */
/* LSI Ready interrupt flag */
#define RCC_CIR_LSIRDYF_Pos             (0U)
#define RCC_CIR_LSIRDYF_Msk             (0x1UL << RCC_CIR_LSIRDYF_Pos)            /*!< 0x00000001 */
#define RCC_CIR_LSIRDYF                 RCC_CIR_LSIRDYF_Msk

/* LSE Ready interrupt flag */
#define RCC_CIR_LSERDYF_Pos             (1U)
#define RCC_CIR_LSERDYF_Msk             (0x1UL << RCC_CIR_LSERDYF_Pos)            /*!< 0x00000002 */
#define RCC_CIR_LSERDYF                 RCC_CIR_LSERDYF_Msk

/* HSI Ready interrupt flag */
#define RCC_CIR_HSIRDYF_Pos             (2U)
#define RCC_CIR_HSIRDYF_Msk             (0x1UL << RCC_CIR_HSIRDYF_Pos)            /*!< 0x00000004 */
#define RCC_CIR_HSIRDYF                 RCC_CIR_HSIRDYF_Msk

/* HSE Ready interrupt flag */
#define RCC_CIR_HSERDYF_Pos             (3U)
#define RCC_CIR_HSERDYF_Msk             (0x1UL << RCC_CIR_HSERDYF_Pos)            /*!< 0x00000008 */
#define RCC_CIR_HSERDYF                 RCC_CIR_HSERDYF_Msk

/* Main PLL ready interrupt flag */
#define RCC_CIR_PLLRDYF_Pos             (4U)
#define RCC_CIR_PLLRDYF_Msk             (0x1UL << RCC_CIR_PLLRDYF_Pos)            /*!< 0x00000010 */
#define RCC_CIR_PLLRDYF                 RCC_CIR_PLLRDYF_Msk

/* PLLI2S Ready interrupt flag */
#define RCC_CIR_PLLI2SRDYF_Pos          (5U)
#define RCC_CIR_PLLI2SRDYF_Msk          (0x1UL << RCC_CIR_PLLI2SRDYF_Pos)         /*!< 0x00000020 */
#define RCC_CIR_PLLI2SRDYF              RCC_CIR_PLLI2SRDYF_Msk

/* PLLSAI Ready interrupt flag */
#define RCC_CIR_PLLSAIRDYF_Pos          (6U)
#define RCC_CIR_PLLSAIRDYF_Msk          (0x1UL << RCC_CIR_PLLSAIRDYF_Pos)         /*!< 0x00000040 */
#define RCC_CIR_PLLSAIRDYF              RCC_CIR_PLLSAIRDYF_Msk

/* Clock security system interrupt flag */
#define RCC_CIR_CSSF_Pos                (7U)
#define RCC_CIR_CSSF_Msk                (0x1UL << RCC_CIR_CSSF_Pos)               /*!< 0x00000080 */
#define RCC_CIR_CSSF                    RCC_CIR_CSSF_Msk

/* LSI Ready interrupt enable */
#define RCC_CIR_LSIRDYE_Pos             (8U)
#define RCC_CIR_LSIRDYE_Msk             (0x1UL << RCC_CIR_LSIRDYE_Pos)            /*!< 0x00000100 */
#define RCC_CIR_LSIRDYE                 RCC_CIR_LSIRDYE_Msk

/* LSE Ready interrupt enable */
#define RCC_CIR_LSERDYE_Pos             (9U)
#define RCC_CIR_LSERDYE_Msk             (0x1UL << RCC_CIR_LSERDYE_Pos)            /*!< 0x00000200 */
#define RCC_CIR_LSERDYE                 RCC_CIR_LSERDYE_Msk

/* HSI Ready interrupt enable */
#define RCC_CIR_HSIRDYE_Pos             (10U)
#define RCC_CIR_HSIRDYE_Msk             (0x1UL << RCC_CIR_HSIRDYE_Pos)            /*!< 0x00000400 */
#define RCC_CIR_HSIRDYE                 RCC_CIR_HSIRDYE_Msk

/* HSE Ready interrupt enable */
#define RCC_CIR_HSERDYE_Pos             (11U)
#define RCC_CIR_HSERDYE_Msk             (0x1UL << RCC_CIR_HSERDYE_Pos)            /*!< 0x00000800 */
#define RCC_CIR_HSERDYE                 RCC_CIR_HSERDYE_Msk

/* Main PLL ready interrupt enable */
#define RCC_CIR_PLLRDYE_Pos             (12U)
#define RCC_CIR_PLLRDYE_Msk             (0x1UL << RCC_CIR_PLLRDYE_Pos)            /*!< 0x00001000 */
#define RCC_CIR_PLLRDYE                 RCC_CIR_PLLRDYE_Msk

/* PLLI2S Ready interrupt enable */
#define RCC_CIR_PLLI2SRDYE_Pos          (13U)
#define RCC_CIR_PLLI2SRDYE_Msk          (0x1UL << RCC_CIR_PLLI2SRDYE_Pos)         /*!< 0x00002000 */
#define RCC_CIR_PLLI2SRDYE              RCC_CIR_PLLI2SRDYE_Msk

/* PLLSAI Ready interrupt enable */
#define RCC_CIR_PLLSAIRDYE_Pos          (14U)
#define RCC_CIR_PLLSAIRDYE_Msk          (0x1UL << RCC_CIR_PLLSAIRDYE_Pos)         /*!< 0x00004000 */
#define RCC_CIR_PLLSAIRDYE              RCC_CIR_PLLSAIRDYE_Msk

/* LSI Ready interrupt clear */
#define RCC_CIR_LSIRDYC_Pos             (16U)
#define RCC_CIR_LSIRDYC_Msk             (0x1UL << RCC_CIR_LSIRDYC_Pos)            /*!< 0x00010000 */
#define RCC_CIR_LSIRDYC                 RCC_CIR_LSIRDYC_Msk

/* LSE Ready interrupt clear */
#define RCC_CIR_LSERDYC_Pos             (17U)
#define RCC_CIR_LSERDYC_Msk             (0x1UL << RCC_CIR_LSERDYC_Pos)            /*!< 0x00020000 */
#define RCC_CIR_LSERDYC                 RCC_CIR_LSERDYC_Msk

/* HSI Ready interrupt clear */
#define RCC_CIR_HSIRDYC_Pos             (18U)
#define RCC_CIR_HSIRDYC_Msk             (0x1UL << RCC_CIR_HSIRDYC_Pos)            /*!< 0x00040000 */
#define RCC_CIR_HSIRDYC                 RCC_CIR_HSIRDYC_Msk

/* HSE Ready interrupt clear */
#define RCC_CIR_HSERDYC_Pos             (19U)
#define RCC_CIR_HSERDYC_Msk             (0x1UL << RCC_CIR_HSERDYC_Pos)            /*!< 0x00080000 */
#define RCC_CIR_HSERDYC                 RCC_CIR_HSERDYC_Msk

/* Main PLL ready interrupt clear */
#define RCC_CIR_PLLRDYC_Pos             (20U)
#define RCC_CIR_PLLRDYC_Msk             (0x1UL << RCC_CIR_PLLRDYC_Pos)            /*!< 0x00100000 */
#define RCC_CIR_PLLRDYC                 RCC_CIR_PLLRDYC_Msk

/* PLLI2S Ready interrupt clear */
#define RCC_CIR_PLLI2SRDYC_Pos          (21U)
#define RCC_CIR_PLLI2SRDYC_Msk          (0x1UL << RCC_CIR_PLLI2SRDYC_Pos)         /*!< 0x00200000 */
#define RCC_CIR_PLLI2SRDYC              RCC_CIR_PLLI2SRDYC_Msk

/* PLLSAI Ready interrupt clear */
#define RCC_CIR_PLLSAIRDYC_Pos          (22U)
#define RCC_CIR_PLLSAIRDYC_Msk          (0x1UL << RCC_CIR_PLLSAIRDYC_Pos)         /*!< 0x00400000 */
#define RCC_CIR_PLLSAIRDYC              RCC_CIR_PLLSAIRDYC_Msk

/* Clock security system interrupt clear*/
#define RCC_CIR_CSSC_Pos                (23U)
#define RCC_CIR_CSSC_Msk                (0x1UL << RCC_CIR_CSSC_Pos)               /*!< 0x00800000 */
#define RCC_CIR_CSSC                    RCC_CIR_CSSC_Msk


/* RCC AHB1 peripheral reset register */
/* IO port A reset */
#define RCC_AHB1RSTR_GPIOARST_Pos       (0U)
#define RCC_AHB1RSTR_GPIOARST_Msk       (0x1UL << RCC_AHB1RSTR_GPIOARST_Pos)      /*!< 0x00000001 */
#define RCC_AHB1RSTR_GPIOARST           RCC_AHB1RSTR_GPIOARST_Msk

/* IO port B reset */
#define RCC_AHB1RSTR_GPIOBRST_Pos       (1U)
#define RCC_AHB1RSTR_GPIOBRST_Msk       (0x1UL << RCC_AHB1RSTR_GPIOBRST_Pos)      /*!< 0x00000002 */
#define RCC_AHB1RSTR_GPIOBRST           RCC_AHB1RSTR_GPIOBRST_Msk

/* IO port C reset */
#define RCC_AHB1RSTR_GPIOCRST_Pos       (2U)
#define RCC_AHB1RSTR_GPIOCRST_Msk       (0x1UL << RCC_AHB1RSTR_GPIOCRST_Pos)      /*!< 0x00000004 */
#define RCC_AHB1RSTR_GPIOCRST           RCC_AHB1RSTR_GPIOCRST_Msk

/* IO port D reset */
#define RCC_AHB1RSTR_GPIODRST_Pos       (3U)
#define RCC_AHB1RSTR_GPIODRST_Msk       (0x1UL << RCC_AHB1RSTR_GPIODRST_Pos)      /*!< 0x00000008 */
#define RCC_AHB1RSTR_GPIODRST           RCC_AHB1RSTR_GPIODRST_Msk

/* IO port E reset */
#define RCC_AHB1RSTR_GPIOERST_Pos       (4U)
#define RCC_AHB1RSTR_GPIOERST_Msk       (0x1UL << RCC_AHB1RSTR_GPIOERST_Pos)      /*!< 0x00000010 */
#define RCC_AHB1RSTR_GPIOERST           RCC_AHB1RSTR_GPIOERST_Msk

/* IO port F reset */
#define RCC_AHB1RSTR_GPIOFRST_Pos       (5U)
#define RCC_AHB1RSTR_GPIOFRST_Msk       (0x1UL << RCC_AHB1RSTR_GPIOFRST_Pos)      /*!< 0x00000020 */
#define RCC_AHB1RSTR_GPIOFRST           RCC_AHB1RSTR_GPIOFRST_Msk

/* IO port G reset */
#define RCC_AHB1RSTR_GPIOGRST_Pos       (6U)
#define RCC_AHB1RSTR_GPIOGRST_Msk       (0x1UL << RCC_AHB1RSTR_GPIOGRST_Pos)      /*!< 0x00000040 */
#define RCC_AHB1RSTR_GPIOGRST           RCC_AHB1RSTR_GPIOGRST_Msk

/* IO port H reset */
#define RCC_AHB1RSTR_GPIOHRST_Pos       (7U)
#define RCC_AHB1RSTR_GPIOHRST_Msk       (0x1UL << RCC_AHB1RSTR_GPIOHRST_Pos)      /*!< 0x00000080 */
#define RCC_AHB1RSTR_GPIOHRST           RCC_AHB1RSTR_GPIOHRST_Msk

/* CRC reset */
#define RCC_AHB1RSTR_CRCRST_Pos         (12U)
#define RCC_AHB1RSTR_CRCRST_Msk         (0x1UL << RCC_AHB1RSTR_CRCRST_Pos)        /*!< 0x00001000 */
#define RCC_AHB1RSTR_CRCRST             RCC_AHB1RSTR_CRCRST_Msk 

/* DMA1 reset */
#define RCC_AHB1RSTR_DMA1RST_Pos        (21U)
#define RCC_AHB1RSTR_DMA1RST_Msk        (0x1UL << RCC_AHB1RSTR_DMA1RST_Pos)       /*!< 0x00200000 */
#define RCC_AHB1RSTR_DMA1RST            RCC_AHB1RSTR_DMA1RST_Msk

/* DMA2 reset */
#define RCC_AHB1RSTR_DMA2RST_Pos        (22U)
#define RCC_AHB1RSTR_DMA2RST_Msk        (0x1UL << RCC_AHB1RSTR_DMA2RST_Pos)       /*!< 0x00400000 */
#define RCC_AHB1RSTR_DMA2RST            RCC_AHB1RSTR_DMA2RST_Msk

/* USB OTG HS module reset */
#define RCC_AHB1RSTR_OTGHSRST_Pos       (29U)
#define RCC_AHB1RSTR_OTGHSRST_Msk       (0x1UL << RCC_AHB1RSTR_OTGHSRST_Pos)      /*!< 0x20000000 */
#define RCC_AHB1RSTR_OTGHSRST           RCC_AHB1RSTR_OTGHSRST_Msk


/* RCC AHB2 peripheral reset register */

/* Camera interface reset */
#define RCC_AHB2RSTR_DCMIRST_Pos        (0U)
#define RCC_AHB2RSTR_DCMIRST_Msk        (0x1UL << RCC_AHB2RSTR_DCMIRST_Pos)       /*!< 0x00000001 */
#define RCC_AHB2RSTR_DCMIRST            RCC_AHB2RSTR_DCMIRST_Msk

/* USB OTG FS module reset */
#define RCC_AHB2RSTR_OTGFSRST_Pos       (7U)
#define RCC_AHB2RSTR_OTGFSRST_Msk       (0x1UL << RCC_AHB2RSTR_OTGFSRST_Pos)      /*!< 0x00000080 */
#define RCC_AHB2RSTR_OTGFSRST           RCC_AHB2RSTR_OTGFSRST_Msk


/* RCC AHB3 peripheral reset register */

/* Flexible memory controller module rest */
#define RCC_AHB3RSTR_FMCRST_Pos         (0U)
#define RCC_AHB3RSTR_FMCRST_Msk         (0x1UL << RCC_AHB3RSTR_FMCRST_Pos)         /*!< 0x00000001 */
#define RCC_AHB3RSTR_FMCRST             RCC_AHB3RSTR_FMCRST_Msk

/* QUADSPI module reset */
#define RCC_AHB3RSTR_QSPIRST_Pos        (1U)
#define RCC_AHB3RSTR_QSPIRST_Msk        (0x1UL << RCC_AHB3RSTR_QSPIRST_Pos)        /*!< 0x00000002 */
#define RCC_AHB3RSTR_QSPIRST            RCC_AHB3RSTR_QSPIRST_Msk

/* RCC APB1 peripheral reset register */

#define RCC_APB1RSTR_TIM2RST_Pos        (0U)
#define RCC_APB1RSTR_TIM2RST_Msk        (0x1UL << RCC_APB1RSTR_TIM2RST_Pos)        /*!< 0x00000001 */
#define RCC_APB1RSTR_TIM2RST            RCC_APB1RSTR_TIM2RST_Msk

#define RCC_APB1RSTR_TIM3RST_Pos        (1U)
#define RCC_APB1RSTR_TIM3RST_Msk        (0x1UL << RCC_APB1RSTR_TIM3RST_Pos)        /*!< 0x00000002 */
#define RCC_APB1RSTR_TIM3RST            RCC_APB1RSTR_TIM3RST_Msk

#define RCC_APB1RSTR_TIM4RST_Pos        (2U)
#define RCC_APB1RSTR_TIM4RST_Msk        (0x1UL << RCC_APB1RSTR_TIM4RST_Pos)        /*!< 0x00000004 */
#define RCC_APB1RSTR_TIM4RST            RCC_APB1RSTR_TIM4RST_Msk

#define RCC_APB1RSTR_TIM5RST_Pos        (3U)
#define RCC_APB1RSTR_TIM5RST_Msk        (0x1UL << RCC_APB1RSTR_TIM5RST_Pos)        /*!< 0x00000008 */
#define RCC_APB1RSTR_TIM5RST            RCC_APB1RSTR_TIM5RST_Msk

#define RCC_APB1RSTR_TIM6RST_Pos        (4U)
#define RCC_APB1RSTR_TIM6RST_Msk        (0x1UL << RCC_APB1RSTR_TIM6RST_Pos)        /*!< 0x00000010 */
#define RCC_APB1RSTR_TIM6RST            RCC_APB1RSTR_TIM6RST_Msk

#define RCC_APB1RSTR_TIM7RST_Pos        (5U)
#define RCC_APB1RSTR_TIM7RST_Msk        (0x1UL << RCC_APB1RSTR_TIM7RST_Pos)        /*!< 0x00000020 */
#define RCC_APB1RSTR_TIM7RST            RCC_APB1RSTR_TIM7RST_Msk

#define RCC_APB1RSTR_TIM12RST_Pos       (6U)
#define RCC_APB1RSTR_TIM12RST_Msk       (0x1UL << RCC_APB1RSTR_TIM12RST_Pos)       /*!< 0x00000040 */
#define RCC_APB1RSTR_TIM12RST           RCC_APB1RSTR_TIM12RST_Msk

#define RCC_APB1RSTR_TIM13RST_Pos       (7U)
#define RCC_APB1RSTR_TIM13RST_Msk       (0x1UL << RCC_APB1RSTR_TIM13RST_Pos)       /*!< 0x00000080 */
#define RCC_APB1RSTR_TIM13RST           RCC_APB1RSTR_TIM13RST_Msk

#define RCC_APB1RSTR_TIM14RST_Pos       (8U)
#define RCC_APB1RSTR_TIM14RST_Msk       (0x1UL << RCC_APB1RSTR_TIM14RST_Pos)       /*!< 0x00000100 */
#define RCC_APB1RSTR_TIM14RST           RCC_APB1RSTR_TIM14RST_Msk

#define RCC_APB1RSTR_WWDGRST_Pos        (11U)
#define RCC_APB1RSTR_WWDGRST_Msk        (0x1UL << RCC_APB1RSTR_WWDGRST_Pos)        /*!< 0x00000800 */
#define RCC_APB1RSTR_WWDGRST            RCC_APB1RSTR_WWDGRST_Msk

#define RCC_APB1RSTR_SPI2RST_Pos        (14U)
#define RCC_APB1RSTR_SPI2RST_Msk        (0x1UL << RCC_APB1RSTR_SPI2RST_Pos)        /*!< 0x00004000 */
#define RCC_APB1RSTR_SPI2RST            RCC_APB1RSTR_SPI2RST_Msk

#define RCC_APB1RSTR_SPI3RST_Pos        (15U)
#define RCC_APB1RSTR_SPI3RST_Msk        (0x1UL << RCC_APB1RSTR_SPI3RST_Pos)        /*!< 0x00008000 */
#define RCC_APB1RSTR_SPI3RST            RCC_APB1RSTR_SPI3RST_Msk

#define RCC_APB1RSTR_SPDIFRXRST_Pos     (16U)
#define RCC_APB1RSTR_SPDIFRXRST_Msk     (0x1UL << RCC_APB1RSTR_SPDIFRXRST_Pos)     /*!< 0x00010000 */
#define RCC_APB1RSTR_SPDIFRXRST         RCC_APB1RSTR_SPDIFRXRST_Msk

#define RCC_APB1RSTR_USART2RST_Pos      (17U)
#define RCC_APB1RSTR_USART2RST_Msk      (0x1UL << RCC_APB1RSTR_USART2RST_Pos)      /*!< 0x00020000 */
#define RCC_APB1RSTR_USART2RST          RCC_APB1RSTR_USART2RST_Msk

#define RCC_APB1RSTR_USART3RST_Pos      (18U)
#define RCC_APB1RSTR_USART3RST_Msk      (0x1UL << RCC_APB1RSTR_USART3RST_Pos)      /*!< 0x00040000 */
#define RCC_APB1RSTR_USART3RST          RCC_APB1RSTR_USART3RST_Msk

#define RCC_APB1RSTR_USART4RST_Pos      (19U)
#define RCC_APB1RSTR_USART4RST_Msk      (0x1UL << RCC_APB1RSTR_USART4RST_Pos)      /*!< 0x00080000 */
#define RCC_APB1RSTR_USART4RST          RCC_APB1RSTR_USART4RST_Msk

#define RCC_APB1RSTR_USART5RST_Pos      (20U)
#define RCC_APB1RSTR_USART5RST_Msk      (0x1UL << RCC_APB1RSTR_USART5RST_Pos)      /*!< 0x00100000 */
#define RCC_APB1RSTR_USART5RST          RCC_APB1RSTR_USART5RST_Msk

#define RCC_APB1RSTR_I2C1RST_Pos        (21U)
#define RCC_APB1RSTR_I2C1RST_Msk        (0x1UL << RCC_APB1RSTR_I2C1RST_Pos)        /*!< 0x00200000 */
#define RCC_APB1RSTR_I2C1RST            RCC_APB1RSTR_I2C1RST_Msk

#define RCC_APB1RSTR_I2C2RST_Pos        (22U)
#define RCC_APB1RSTR_I2C2RST_Msk        (0x1UL << RCC_APB1RSTR_I2C2RST_Pos)        /*!< 0x00400000 */
#define RCC_APB1RSTR_I2C2RST            RCC_APB1RSTR_I2C2RST_Msk

#define RCC_APB1RSTR_I2C3RST_Pos        (23U)
#define RCC_APB1RSTR_I2C3RST_Msk        (0x1UL << RCC_APB1RSTR_I2C3RST_Pos)        /*!< 0x00800000 */
#define RCC_APB1RSTR_I2C3RST            RCC_APB1RSTR_I2C3RST_Msk

#define RCC_APB1RSTR_FMPI2C1RST_Pos     (24U)
#define RCC_APB1RSTR_FMPI2C1RST_Msk     (0x1UL << RCC_APB1RSTR_FMPI2C1RST_Pos)     /*!< 0x01000000 */
#define RCC_APB1RSTR_FMPI2C1RST         RCC_APB1RSTR_FMPI2C1RST_Msk

#define RCC_APB1RSTR_CAN1RST_Pos        (25U)
#define RCC_APB1RSTR_CAN1RST_Msk        (0x1UL << RCC_APB1RSTR_CAN1RST_Pos)        /*!< 0x02000000 */
#define RCC_APB1RSTR_CAN1RST            RCC_APB1RSTR_CAN1RST_Msk

#define RCC_APB1RSTR_CAN2RST_Pos        (26U)
#define RCC_APB1RSTR_CAN2RST_Msk        (0x1UL << RCC_APB1RSTR_CAN2RST_Pos)        /*!< 0x04000000 */
#define RCC_APB1RSTR_CAN2RST            RCC_APB1RSTR_CAN2RST_Msk

#define RCC_APB1RSTR_CECRST_Pos         (27U)
#define RCC_APB1RSTR_CECRST_Msk         (0x1UL << RCC_APB1RSTR_CECRST_Pos)         /*!< 0x08000000 */
#define RCC_APB1RSTR_CECRST             RCC_APB1RSTR_CECRST_Msk

#define RCC_APB1RSTR_PWRRST_Pos         (28U)
#define RCC_APB1RSTR_PWRRST_Msk         (0x1UL << RCC_APB1RSTR_PWRRST_Pos)         /*!< 0x10000000 */
#define RCC_APB1RSTR_PWRRST             RCC_APB1RSTR_PWRRST_Msk

#define RCC_APB1RSTR_DACRST_Pos         (29U)
#define RCC_APB1RSTR_DACRST_Msk         (0x1UL << RCC_APB1RSTR_DACRST_Pos)         /*!< 0x20000000 */
#define RCC_APB1RSTR_DACRST             RCC_APB1RSTR_DACRST_Msk


/* RCC APB2 peripheral reset register */

#define RCC_APB2RSTR_TIM1RST_Pos        (0U)
#define RCC_APB2RSTR_TIM1RST_Msk        (0x1UL << RCC_APB2RSTR_TIM1RST_Pos)        /*!< 0x00000001 */
#define RCC_APB2RSTR_TIM1RST            RCC_APB2RSTR_TIM1RST_Msk

#define RCC_APB2RSTR_TIM8RST_Pos        (1U)
#define RCC_APB2RSTR_TIM8RST_Msk        (0x1UL << RCC_APB2RSTR_TIM8RST_Pos)        /*!< 0x00000002 */
#define RCC_APB2RSTR_TIM8RST            RCC_APB2RSTR_TIM8RST_Msk

#define RCC_APB2RSTR_USART1RST_Pos      (4U)
#define RCC_APB2RSTR_USART1RST_Msk      (0x1UL << RCC_APB2RSTR_USART1RST_Pos)      /*!< 0x00000010 */
#define RCC_APB2RSTR_USART1RST          RCC_APB2RSTR_USART1RST_Msk

#define RCC_APB2RSTR_USART6RST_Pos      (5U)
#define RCC_APB2RSTR_USART6RST_Msk      (0x1UL << RCC_APB2RSTR_USART6RST_Pos)      /*!< 0x00000020 */
#define RCC_APB2RSTR_USART6RST          RCC_APB2RSTR_USART6RST_Msk

#define RCC_APB2RSTR_ADCRST_Pos         (8U)
#define RCC_APB2RSTR_ADCRST_Msk         (0x1UL << RCC_APB2RSTR_ADCRST_Pos)         /*!< 0x00000100 */
#define RCC_APB2RSTR_ADCRST             RCC_APB2RSTR_ADCRST_Msk

#define RCC_APB2RSTR_SPIORST_Pos        (11U)
#define RCC_APB2RSTR_SPIORST_Msk        (0x1UL << RCC_APB2RSTR_SPIORST_Pos)        /*!< 0x00000800 */
#define RCC_APB2RSTR_SPIORST            RCC_APB2RSTR_SPIORST_Msk

#define RCC_APB2RSTR_SPI1RST_Pos        (12U)
#define RCC_APB2RSTR_SPI1RST_Msk        (0x1UL << RCC_APB2RSTR_SPI1RST_Pos)        /*!< 0x00001000 */
#define RCC_APB2RSTR_SPI1RST            RCC_APB2RSTR_SPI1RST_Msk

#define RCC_APB2RSTR_SPI4RST_Pos        (13U)
#define RCC_APB2RSTR_SPI4RST_Msk        (0x1UL << RCC_APB2RSTR_SPI4RST_Pos)        /*!< 0x00002000 */
#define RCC_APB2RSTR_SPI4RST            RCC_APB2RSTR_SPI4RST_Msk

#define RCC_APB2RSTR_SYSCFGRST_Pos      (14U)
#define RCC_APB2RSTR_SYSCFGRST_Msk      (0x1UL << RCC_APB2RSTR_SYSCFGRST_Pos)      /*!< 0x00002000 */
#define RCC_APB2RSTR_SYSCFGRST          RCC_APB2RSTR_SYSCFGRST_Msk

#define RCC_APB2RSTR_TIM9RST_Pos        (16U)
#define RCC_APB2RSTR_TIM9RST_Msk        (0x1UL << RCC_APB2RSTR_TIM9RST_Pos)        /*!< 0x00010000 */
#define RCC_APB2RSTR_TIM9RST            RCC_APB2RSTR_TIM9RST_Msk

#define RCC_APB2RSTR_TIM10RST_Pos       (17U)
#define RCC_APB2RSTR_TIM10RST_Msk       (0x1UL << RCC_APB2RSTR_TIM10RST_Pos)       /*!< 0x00020000 */
#define RCC_APB2RSTR_TIM10RST           RCC_APB2RSTR_TIM10RST_Msk

#define RCC_APB2RSTR_TIM11RST_Pos       (18U)
#define RCC_APB2RSTR_TIM11RST_Msk       (0x1UL << RCC_APB2RSTR_TIM11RST_Pos)       /*!< 0x00040000 */
#define RCC_APB2RSTR_TIM11RST           RCC_APB2RSTR_TIM11RST_Msk

#define RCC_APB2RSTR_SAI1RST_Pos        (22U)
#define RCC_APB2RSTR_SAI1RST_Msk        (0x1UL << RCC_APB2RSTR_SAI1RST_Pos)        /*!< 0x00400000 */
#define RCC_APB2RSTR_SAI1RST            RCC_APB2RSTR_SAI1RST_Msk

#define RCC_APB2RSTR_SAI2RST_Pos        (23U)
#define RCC_APB2RSTR_SAI2RST_Msk        (0x1UL << RCC_APB2RSTR_SAI2RST_Pos)        /*!< 0x00800000 */
#define RCC_APB2RSTR_SAI2RST            RCC_APB2RSTR_SAI2RST_Msk


/* RCC AHB1 peripheral clock enable register */

/* IO port A enable */
#define RCC_AHB1LPENR_GPIOALPEN_Pos     (0U)
#define RCC_AHB1LPENR_GPIOALPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOALPEN_Pos)     /*!< 0x00000001 */
#define RCC_AHB1LPENR_GPIOALPEN         RCC_AHB1LPENR_GPIOALPEN_Msk

/* IO port B enable */
#define RCC_AHB1LPENR_GPIOBLPEN_Pos     (1U)
#define RCC_AHB1LPENR_GPIOBLPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOBLPEN_Pos)     /*!< 0x00000002 */
#define RCC_AHB1LPENR_GPIOBLPEN         RCC_AHB1LPENR_GPIOBLPEN_Msk

/* IO port C enable */
#define RCC_AHB1LPENR_GPIOCLPEN_Pos     (2U)
#define RCC_AHB1LPENR_GPIOCLPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOCLPEN_Pos)     /*!< 0x00000004 */
#define RCC_AHB1LPENR_GPIOCLPEN         RCC_AHB1LPENR_GPIOCLPEN_Msk

/* IO port D enable */
#define RCC_AHB1LPENR_GPIODLPEN_Pos     (3U)
#define RCC_AHB1LPENR_GPIODLPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIODLPEN_Pos)     /*!< 0x00000008 */
#define RCC_AHB1LPENR_GPIODLPEN         RCC_AHB1LPENR_GPIODLPEN_Msk

/* IO port E enable */
#define RCC_AHB1LPENR_GPIOELPEN_Pos     (4U)
#define RCC_AHB1LPENR_GPIOELPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOELPEN_Pos)     /*!< 0x00000010 */
#define RCC_AHB1LPENR_GPIOELPEN         RCC_AHB1LPENR_GPIOELPEN_Msk

/* IO port F enable */
#define RCC_AHB1LPENR_GPIOFLPEN_Pos     (5U)
#define RCC_AHB1LPENR_GPIOFLPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOFLPEN_Pos)     /*!< 0x00000020 */
#define RCC_AHB1LPENR_GPIOFLPEN         RCC_AHB1LPENR_GPIOFLPEN_Msk

/* IO port G enable */
#define RCC_AHB1LPENR_GPIOGLPEN_Pos     (6U)
#define RCC_AHB1LPENR_GPIOGLPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOGLPEN_Pos)     /*!< 0x00000040 */
#define RCC_AHB1LPENR_GPIOGLPEN         RCC_AHB1LPENR_GPIOGLPEN_Msk

/* IO port H enable */
#define RCC_AHB1LPENR_GPIOHLPEN_Pos     (7U)
#define RCC_AHB1LPENR_GPIOHLPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOHLPEN_Pos)     /*!< 0x00000080 */
#define RCC_AHB1LPENR_GPIOHLPEN         RCC_AHB1LPENR_GPIOHLPEN_Msk

/* CRC enable */
#define RCC_AHB1LPENR_CRCLPEN_Pos       (12U)
#define RCC_AHB1LPENR_CRCLPEN_Msk       (0x1UL << RCC_AHB1LPENR_CRCLPEN_Pos)       /*!< 0x00001000 */
#define RCC_AHB1LPENR_CRCLPEN           RCC_AHB1LPENR_CRCLPEN_Msk 

/* Backup SRAM interface clock enable */
#define RCC_AHB1LPENR_BKPSRAMLPEN_Pos   (18U)
#define RCC_AHB1LPENR_BKPSRAMLPEN_Msk   (0x1UL << RCC_AHB1LPENR_BKPSRAMLPEN_Pos)   /*!< 0x00001000 */
#define RCC_AHB1LPENR_BKPSRAMLPEN       RCC_AHB1LPENR_BKPSRAMLPEN_Msk 

/* DMA1 enable */
#define RCC_AHB1LPENR_DMA1LPEN_Pos      (21U)
#define RCC_AHB1LPENR_DMA1LPEN_Msk      (0x1UL << RCC_AHB1LPENR_DMA1LPEN_Pos)      /*!< 0x00200000 */
#define RCC_AHB1LPENR_DMA1LPEN          RCC_AHB1LPENR_DMA1LPEN_Msk

/* DMA2 enable */
#define RCC_AHB1LPENR_DMA2LPEN_Pos      (22U)
#define RCC_AHB1LPENR_DMA2LPEN_Msk      (0x1UL << RCC_AHB1LPENR_DMA2LPEN_Pos)      /*!< 0x00400000 */
#define RCC_AHB1LPENR_DMA2LPEN          RCC_AHB1LPENR_DMA2LPEN_Msk

/* USB OTG HS module enable */
#define RCC_AHB1LPENR_OTGHSLPEN_Pos     (29U)
#define RCC_AHB1LPENR_OTGHSLPEN_Msk     (0x1UL << RCC_AHB1LPENR_OTGHSLPEN_Pos)     /*!< 0x20000000 */
#define RCC_AHB1LPENR_OTGHSLPEN         RCC_AHB1LPENR_OTGHSLPEN_Msk

/* USB OTG HSULPI module enable */
#define RCC_AHB1LPENR_OTGHSULPILPEN_Pos (30U)
#define RCC_AHB1LPENR_OTGHSULPILPEN_Msk (0x1UL << RCC_AHB1LPENR_OTGHSULPILPEN_Pos) /*!< 0x20000000 */
#define RCC_AHB1LPENR_OTGHSULPILPEN     RCC_AHB1LPENR_OTGHSULPILPEN_Msk



/* RCC AHB2 peripheral clock enable register */

/* Camera interface enable */
#define RCC_AHB2LPENR_DCMILPEN_Pos      (0U)
#define RCC_AHB2LPENR_DCMILPEN_Msk      (0x1UL << RCC_AHB2LPENR_DCMILPEN_Pos)      /*!< 0x00000001 */
#define RCC_AHB2LPENR_DCMILPEN          RCC_AHB2LPENR_DCMILPEN_Msk

/* USB OTG FS clock enable */
#define RCC_AHB2LPENR_OTGFSLPEN_Pos     (7U)
#define RCC_AHB2LPENR_OTGFSLPEN_Msk     (0x1UL << RCC_AHB2LPENR_OTGFSLPEN_Pos)     /*!< 0x00000080 */
#define RCC_AHB2LPENR_OTGFSLPEN         RCC_AHB2LPENR_OTGFSLPEN_Msk



/* RCC AHB3 peripheral clock enable register */

/* Flexible memory controller module enable */
#define RCC_AHB3LPENR_FMCLPEN_Pos       (0U)
#define RCC_AHB3LPENR_FMCLPEN_Msk       (0x1UL << RCC_AHB3LPENR_FMCLPEN_Pos)       /*!< 0x00000001 */
#define RCC_AHB3LPENR_FMCLPEN           RCC_AHB3LPENR_FMCLPEN_Msk

/* QUADSPI module enable */
#define RCC_AHB3LPENR_QSPILPEN_Pos      (1U)
#define RCC_AHB3LPENR_QSPILPEN_Msk      (0x1UL << RCC_AHB3LPENR_QSPILPEN_Pos)      /*!< 0x00000002 */
#define RCC_AHB3LPENR_QSPILPEN          RCC_AHB3LPENR_QSPILPEN_Msk


/* RCC APB1 peripheral enable register */

#define RCC_APB1LPENR_TIM2LPEN_Pos      (0U)
#define RCC_APB1LPENR_TIM2LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM2LPEN_Pos)      /*!< 0x00000001 */
#define RCC_APB1LPENR_TIM2LPEN          RCC_APB1LPENR_TIM2LPEN_Msk

#define RCC_APB1LPENR_TIM3LPEN_Pos      (1U)
#define RCC_APB1LPENR_TIM3LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM3LPEN_Pos)      /*!< 0x00000002 */
#define RCC_APB1LPENR_TIM3LPEN          RCC_APB1LPENR_TIM3LPEN_Msk

#define RCC_APB1LPENR_TIM4LPEN_Pos      (2U)
#define RCC_APB1LPENR_TIM4LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM4LPEN_Pos)      /*!< 0x00000004 */
#define RCC_APB1LPENR_TIM4LPEN          RCC_APB1LPENR_TIM4LPEN_Msk

#define RCC_APB1LPENR_TIM5LPEN_Pos      (3U)
#define RCC_APB1LPENR_TIM5LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM5LPEN_Pos)      /*!< 0x00000008 */
#define RCC_APB1LPENR_TIM5LPEN          RCC_APB1LPENR_TIM5LPEN_Msk

#define RCC_APB1LPENR_TIM6LPEN_Pos      (4U)
#define RCC_APB1LPENR_TIM6LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM6LPEN_Pos)      /*!< 0x00000010 */
#define RCC_APB1LPENR_TIM6LPEN          RCC_APB1LPENR_TIM6LPEN_Msk

#define RCC_APB1LPENR_TIM7LPEN_Pos      (5U)
#define RCC_APB1LPENR_TIM7LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM7LPEN_Pos)      /*!< 0x00000020 */
#define RCC_APB1LPENR_TIM7LPEN          RCC_APB1LPENR_TIM7LPEN_Msk

#define RCC_APB1LPENR_TIM12LPEN_Pos     (6U)
#define RCC_APB1LPENR_TIM12LPEN_Msk     (0x1UL << RCC_APB1LPENR_TIM12LPEN_Pos)     /*!< 0x00000040 */
#define RCC_APB1LPENR_TIM12LPEN         RCC_APB1LPENR_TIM12LPEN_Msk

#define RCC_APB1LPENR_TIM13LPEN_Pos     (7U)
#define RCC_APB1LPENR_TIM13LPEN_Msk     (0x1UL << RCC_APB1LPENR_TIM13LPEN_Pos)     /*!< 0x00000080 */
#define RCC_APB1LPENR_TIM13LPEN         RCC_APB1LPENR_TIM13LPEN_Msk

#define RCC_APB1LPENR_TIM14LPEN_Pos     (8U)
#define RCC_APB1LPENR_TIM14LPEN_Msk     (0x1UL << RCC_APB1LPENR_TIM14LPEN_Pos)     /*!< 0x00000100 */
#define RCC_APB1LPENR_TIM14LPEN         RCC_APB1LPENR_TIM14LPEN_Msk

#define RCC_APB1LPENR_WWDGLPEN_Pos      (11U)
#define RCC_APB1LPENR_WWDGLPEN_Msk      (0x1UL << RCC_APB1LPENR_WWDGLPEN_Pos)      /*!< 0x00000800 */
#define RCC_APB1LPENR_WWDGLPEN          RCC_APB1LPENR_WWDGLPEN_Msk

#define RCC_APB1LPENR_SPI2LPEN_Pos      (14U)
#define RCC_APB1LPENR_SPI2LPEN_Msk      (0x1UL << RCC_APB1LPENR_SPI2LPEN_Pos)      /*!< 0x00004000 */
#define RCC_APB1LPENR_SPI2LPEN          RCC_APB1LPENR_SPI2LPEN_Msk

#define RCC_APB1LPENR_SPI3LPEN_Pos      (15U)
#define RCC_APB1LPENR_SPI3LPEN_Msk      (0x1UL << RCC_APB1LPENR_SPI3LPEN_Pos)      /*!< 0x00008000 */
#define RCC_APB1LPENR_SPI3LPEN          RCC_APB1LPENR_SPI3LPEN_Msk

#define RCC_APB1LPENR_SPDIFRXLPEN_Pos   (16U)
#define RCC_APB1LPENR_SPDIFRXLPEN_Msk   (0x1UL << RCC_APB1LPENR_SPDIFRXLPEN_Pos)   /*!< 0x00010000 */
#define RCC_APB1LPENR_SPDIFRXLPEN       RCC_APB1LPENR_SPDIFRXLPEN_Msk

#define RCC_APB1LPENR_USART2LPEN_Pos    (17U)
#define RCC_APB1LPENR_USART2LPEN_Msk    (0x1UL << RCC_APB1LPENR_USART2LPEN_Pos)    /*!< 0x00020000 */
#define RCC_APB1LPENR_USART2LPEN        RCC_APB1LPENR_USART2LPEN_Msk

#define RCC_APB1LPENR_USART3LPEN_Pos    (18U)
#define RCC_APB1LPENR_USART3LPEN_Msk    (0x1UL << RCC_APB1LPENR_USART3LPEN_Pos)    /*!< 0x00040000 */
#define RCC_APB1LPENR_USART3LPEN        RCC_APB1LPENR_USART3LPEN_Msk

#define RCC_APB1LPENR_USART4LPEN_Pos    (19U)
#define RCC_APB1LPENR_USART4LPEN_Msk    (0x1UL << RCC_APB1LPENR_USART4LPEN_Pos)    /*!< 0x00080000 */
#define RCC_APB1LPENR_USART4LPEN        RCC_APB1LPENR_USART4LPEN_Msk

#define RCC_APB1LPENR_USART5LPEN_Pos    (20U)
#define RCC_APB1LPENR_USART5LPEN_Msk    (0x1UL << RCC_APB1LPENR_USART5LPEN_Pos)    /*!< 0x00100000 */
#define RCC_APB1LPENR_USART5LPEN        RCC_APB1LPENR_USART5LPEN_Msk

#define RCC_APB1LPENR_I2C1LPEN_Pos      (21U)
#define RCC_APB1LPENR_I2C1LPEN_Msk      (0x1UL << RCC_APB1LPENR_I2C1LPEN_Pos)      /*!< 0x00200000 */
#define RCC_APB1LPENR_I2C1LPEN          RCC_APB1LPENR_I2C1LPEN_Msk

#define RCC_APB1LPENR_I2C2LPEN_Pos      (22U)
#define RCC_APB1LPENR_I2C2LPEN_Msk      (0x1UL << RCC_APB1LPENR_I2C2LPEN_Pos)      /*!< 0x00400000 */
#define RCC_APB1LPENR_I2C2LPEN          RCC_APB1LPENR_I2C2LPEN_Msk

#define RCC_APB1LPENR_I2C3LPEN_Pos      (23U)
#define RCC_APB1LPENR_I2C3LPEN_Msk      (0x1UL << RCC_APB1LPENR_I2C3LPEN_Pos)      /*!< 0x00800000 */
#define RCC_APB1LPENR_I2C3LPEN          RCC_APB1LPENR_I2C3LPEN_Msk

#define RCC_APB1LPENR_FMPI2C1LPEN_Pos   (24U)
#define RCC_APB1LPENR_FMPI2C1LPEN_Msk   (0x1UL << RCC_APB1LPENR_FMPI2C1LPEN_Pos)   /*!< 0x01000000 */
#define RCC_APB1LPENR_FMPI2C1LPEN       RCC_APB1LPENR_FMPI2C1LPEN_Msk

#define RCC_APB1LPENR_CAN1LPEN_Pos      (25U)
#define RCC_APB1LPENR_CAN1LPEN_Msk      (0x1UL << RCC_APB1LPENR_CAN1LPEN_Pos)      /*!< 0x02000000 */
#define RCC_APB1LPENR_CAN1LPEN          RCC_APB1LPENR_CAN1LPEN_Msk

#define RCC_APB1LPENR_CAN2LPEN_Pos      (26U)
#define RCC_APB1LPENR_CAN2LPEN_Msk      (0x1UL << RCC_APB1LPENR_CAN2LPEN_Pos)      /*!< 0x04000000 */
#define RCC_APB1LPENR_CAN2LPEN          RCC_APB1LPENR_CAN2LPEN_Msk

#define RCC_APB1LPENR_CECLPEN_Pos       (27U)
#define RCC_APB1LPENR_CECLPEN_Msk       (0x1UL << RCC_APB1LPENR_CECLPEN_Pos)       /*!< 0x08000000 */
#define RCC_APB1LPENR_CECLPEN           RCC_APB1LPENR_CECLPEN_Msk

#define RCC_APB1LPENR_PWRLPEN_Pos       (28U)
#define RCC_APB1LPENR_PWRLPEN_Msk       (0x1UL << RCC_APB1LPENR_PWRLPEN_Pos)       /*!< 0x10000000 */
#define RCC_APB1LPENR_PWRLPEN           RCC_APB1LPENR_PWRLPEN_Msk

#define RCC_APB1LPENR_DACLPEN_Pos       (29U)
#define RCC_APB1LPENR_DACLPEN_Msk       (0x1UL << RCC_APB1LPENR_DACLPEN_Pos)       /*!< 0x20000000 */
#define RCC_APB1LPENR_DACLPEN           RCC_APB1LPENR_DACLPEN_Msk


/* RCC APB2 peripheral enable register  */

#define RCC_APB2LPENR_TIM1LPEN_Pos      (0U)
#define RCC_APB2LPENR_TIM1LPEN_Msk      (0x1UL << RCC_APB2LPENR_TIM1LPEN_Pos)      /*!< 0x00000001 */
#define RCC_APB2LPENR_TIM1LPEN          RCC_APB2LPENR_TIM1LPEN_Msk

#define RCC_APB2LPENR_TIM8LPEN_Pos      (1U)
#define RCC_APB2LPENR_TIM8LPEN_Msk      (0x1UL << RCC_APB2LPENR_TIM8LPEN_Pos)      /*!< 0x00000002 */
#define RCC_APB2LPENR_TIM8LPEN          RCC_APB2LPENR_TIM8LPEN_Msk

#define RCC_APB2LPENR_USART1LPEN_Pos    (4U)
#define RCC_APB2LPENR_USART1LPEN_Msk    (0x1UL << RCC_APB2LPENR_USART1LPEN_Pos)    /*!< 0x00000010 */
#define RCC_APB2LPENR_USART1LPEN        RCC_APB2LPENR_USART1LPEN_Msk

#define RCC_APB2LPENR_USART6LPEN_Pos    (5U)
#define RCC_APB2LPENR_USART6LPEN_Msk    (0x1UL << RCC_APB2LPENR_USART6LPEN_Pos)    /*!< 0x00000020 */
#define RCC_APB2LPENR_USART6LPEN        RCC_APB2LPENR_USART6LPEN_Msk

#define RCC_APB2LPENR_ADCLPEN_Pos       (8U)
#define RCC_APB2LPENR_ADCLPEN_Msk       (0x1UL << RCC_APB2LPENR_ADCLPEN_Pos)       /*!< 0x00000100 */
#define RCC_APB2LPENR_ADCLPEN           RCC_APB2LPENR_ADCLPEN_Msk

#define RCC_APB2LPENR_SPIOLPEN_Pos      (11U)
#define RCC_APB2LPENR_SPIOLPEN_Msk      (0x1UL << RCC_APB2LPENR_SPIOLPEN_Pos)      /*!< 0x00000800 */
#define RCC_APB2LPENR_SPIOLPEN          RCC_APB2LPENR_SPIOLPEN_Msk

#define RCC_APB2LPENR_SPI1LPEN_Pos      (12U)
#define RCC_APB2LPENR_SPI1LPEN_Msk      (0x1UL << RCC_APB2LPENR_SPI1LPEN_Pos)      /*!< 0x00001000 */
#define RCC_APB2LPENR_SPI1LPEN          RCC_APB2LPENR_SPI1LPEN_Msk

#define RCC_APB2LPENR_SPI4LPEN_Pos      (13U)
#define RCC_APB2LPENR_SPI4LPEN_Msk      (0x1UL << RCC_APB2LPENR_SPI4LPEN_Pos)      /*!< 0x00002000 */
#define RCC_APB2LPENR_SPI4LPEN          RCC_APB2LPENR_SPI4LPEN_Msk

#define RCC_APB2LPENR_SYSCFGLPEN_Pos    (14U)
#define RCC_APB2LPENR_SYSCFGLPEN_Msk    (0x1UL << RCC_APB2LPENR_SYSCFGLPEN_Pos)    /*!< 0x00002000 */
#define RCC_APB2LPENR_SYSCFGLPEN        RCC_APB2LPENR_SYSCFGLPEN_Msk

#define RCC_APB2LPENR_TIM9LPEN_Pos      (16U)
#define RCC_APB2LPENR_TIM9LPEN_Msk      (0x1UL << RCC_APB2LPENR_TIM9LPEN_Pos)      /*!< 0x00010000 */
#define RCC_APB2LPENR_TIM9LPEN          RCC_APB2LPENR_TIM9LPEN_Msk

#define RCC_APB2LPENR_TIM10LPEN_Pos     (17U)
#define RCC_APB2LPENR_TIM10LPEN_Msk     (0x1UL << RCC_APB2LPENR_TIM10LPEN_Pos)     /*!< 0x00020000 */
#define RCC_APB2LPENR_TIM10LPEN         RCC_APB2LPENR_TIM10LPEN_Msk

#define RCC_APB2LPENR_TIM11LPEN_Pos     (18U)
#define RCC_APB2LPENR_TIM11LPEN_Msk     (0x1UL << RCC_APB2LPENR_TIM11LPEN_Pos)     /*!< 0x00040000 */
#define RCC_APB2LPENR_TIM11LPEN         RCC_APB2LPENR_TIM11LPEN_Msk

#define RCC_APB2LPENR_SAI1LPEN_Pos      (22U)
#define RCC_APB2LPENR_SAI1LPEN_Msk      (0x1UL << RCC_APB2LPENR_SAI1LPEN_Pos)      /*!< 0x00400000 */
#define RCC_APB2LPENR_SAI1LPEN          RCC_APB2LPENR_SAI1LPEN_Msk

#define RCC_APB2LPENR_SAI2LPEN_Pos      (23U)
#define RCC_APB2LPENR_SAI2LPEN_Msk      (0x1UL << RCC_APB2LPENR_SAI2LPEN_Pos)      /*!< 0x00800000 */
#define RCC_APB2LPENR_SAI2LPEN          RCC_APB2LPENR_SAI2LPEN_Msk

/* RCC AHB1 peripheral clock enable in low power mode register */

/* IO port A enable in low power mode */
#define RCC_AHB1LPENR_GPIOALPEN_Pos     (0U)
#define RCC_AHB1LPENR_GPIOALPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOALPEN_Pos)     /*!< 0x00000001 */
#define RCC_AHB1LPENR_GPIOALPEN         RCC_AHB1LPENR_GPIOALPEN_Msk

/* IO port B enable in low power mode */
#define RCC_AHB1LPENR_GPIOBLPEN_Pos     (1U)
#define RCC_AHB1LPENR_GPIOBLPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOBLPEN_Pos)     /*!< 0x00000002 */
#define RCC_AHB1LPENR_GPIOBLPEN         RCC_AHB1LPENR_GPIOBLPEN_Msk

/* IO port C enable in low power mode */
#define RCC_AHB1LPENR_GPIOCLPEN_Pos     (2U)
#define RCC_AHB1LPENR_GPIOCLPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOCLPEN_Pos)     /*!< 0x00000004 */
#define RCC_AHB1LPENR_GPIOCLPEN         RCC_AHB1LPENR_GPIOCLPEN_Msk

/* IO port D enable in low power mode */
#define RCC_AHB1LPENR_GPIODLPEN_Pos     (3U)
#define RCC_AHB1LPENR_GPIODLPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIODLPEN_Pos)     /*!< 0x00000008 */
#define RCC_AHB1LPENR_GPIODLPEN         RCC_AHB1LPENR_GPIODLPEN_Msk

/* IO port E enable in low power mode */
#define RCC_AHB1LPENR_GPIOELPEN_Pos     (4U)
#define RCC_AHB1LPENR_GPIOELPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOELPEN_Pos)     /*!< 0x00000010 */
#define RCC_AHB1LPENR_GPIOELPEN         RCC_AHB1LPENR_GPIOELPEN_Msk

/* IO port F enable in low power mode */
#define RCC_AHB1LPENR_GPIOFLPEN_Pos     (5U)
#define RCC_AHB1LPENR_GPIOFLPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOFLPEN_Pos)     /*!< 0x00000020 */
#define RCC_AHB1LPENR_GPIOFLPEN         RCC_AHB1LPENR_GPIOFLPEN_Msk

/* IO port G enable in low power mode */
#define RCC_AHB1LPENR_GPIOGLPEN_Pos     (6U)
#define RCC_AHB1LPENR_GPIOGLPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOGLPEN_Pos)     /*!< 0x00000040 */
#define RCC_AHB1LPENR_GPIOGLPEN         RCC_AHB1LPENR_GPIOGLPEN_Msk

/* IO port H enable in low power mode */
#define RCC_AHB1LPENR_GPIOHLPEN_Pos     (7U)
#define RCC_AHB1LPENR_GPIOHLPEN_Msk     (0x1UL << RCC_AHB1LPENR_GPIOHLPEN_Pos)     /*!< 0x00000080 */
#define RCC_AHB1LPENR_GPIOHLPEN         RCC_AHB1LPENR_GPIOHLPEN_Msk

/* CRC enable in low power mode */
#define RCC_AHB1LPENR_CRCLPEN_Pos       (12U)
#define RCC_AHB1LPENR_CRCLPEN_Msk       (0x1UL << RCC_AHB1LPENR_CRCLPEN_Pos)       /*!< 0x00001000 */
#define RCC_AHB1LPENR_CRCLPEN           RCC_AHB1LPENR_CRCLPEN_Msk 

/* Backup SRAM interface clock enable in low power mode */
#define RCC_AHB1LPENR_BKPSRAMLPEN_Pos   (18U)
#define RCC_AHB1LPENR_BKPSRAMLPEN_Msk   (0x1UL << RCC_AHB1LPENR_BKPSRAMLPEN_Pos)   /*!< 0x00001000 */
#define RCC_AHB1LPENR_BKPSRAMLPEN       RCC_AHB1LPENR_BKPSRAMLPEN_Msk 

/* DMA1 enable in low power mode */
#define RCC_AHB1LPENR_DMA1LPEN_Pos      (21U)
#define RCC_AHB1LPENR_DMA1LPEN_Msk      (0x1UL << RCC_AHB1LPENR_DMA1LPEN_Pos)      /*!< 0x00200000 */
#define RCC_AHB1LPENR_DMA1LPEN          RCC_AHB1LPENR_DMA1LPEN_Msk

/* DMA2 enable in low power mode */
#define RCC_AHB1LPENR_DMA2LPEN_Pos      (22U)
#define RCC_AHB1LPENR_DMA2LPEN_Msk      (0x1UL << RCC_AHB1LPENR_DMA2LPEN_Pos)      /*!< 0x00400000 */
#define RCC_AHB1LPENR_DMA2LPEN          RCC_AHB1LPENR_DMA2LPEN_Msk

/* USB OTG HS module enable in low power mode */
#define RCC_AHB1LPENR_OTGHSLPEN_Pos     (29U)
#define RCC_AHB1LPENR_OTGHSLPEN_Msk     (0x1UL << RCC_AHB1LPENR_OTGHSLPEN_Pos)     /*!< 0x20000000 */
#define RCC_AHB1LPENR_OTGHSLPEN         RCC_AHB1LPENR_OTGHSLPEN_Msk

/* USB OTG HSULPI module enable in low power mode */
#define RCC_AHB1LPENR_OTGHSULPILPEN_Pos (30U)
#define RCC_AHB1LPENR_OTGHSULPILPEN_Msk (0x1UL << RCC_AHB1LPENR_OTGHSULPILPEN_Pos) /*!< 0x20000000 */
#define RCC_AHB1LPENR_OTGHSULPILPEN     RCC_AHB1LPENR_OTGHSULPILPEN_Msk



/* RCC AHB2 peripheral clock enable in low power mode register */

/* Camera interface enable in low power mode */
#define RCC_AHB2LPENR_DCMILPEN_Pos      (0U)
#define RCC_AHB2LPENR_DCMILPEN_Msk      (0x1UL << RCC_AHB2LPENR_DCMILPEN_Pos)      /*!< 0x00000001 */
#define RCC_AHB2LPENR_DCMILPEN          RCC_AHB2LPENR_DCMILPEN_Msk

/* USB OTG FS clock enable in low power mode */
#define RCC_AHB2LPENR_OTGFSLPEN_Pos     (7U)
#define RCC_AHB2LPENR_OTGFSLPEN_Msk     (0x1UL << RCC_AHB2LPENR_OTGFSLPEN_Pos)     /*!< 0x00000080 */
#define RCC_AHB2LPENR_OTGFSLPEN         RCC_AHB2LPENR_OTGFSLPEN_Msk



/* RCC AHB3 peripheral clock enable in low power mode register */

/* Flexible memory controller module enable */
#define RCC_AHB3LPENR_FMCLPEN_Pos       (0U)
#define RCC_AHB3LPENR_FMCLPEN_Msk       (0x1UL << RCC_AHB3LPENR_FMCLPEN_Pos)       /*!< 0x00000001 */
#define RCC_AHB3LPENR_FMCLPEN           RCC_AHB3LPENR_FMCLPEN_Msk

/* QUADSPI module enable in low power mode */
#define RCC_AHB3LPENR_QSPILPEN_Pos      (1U)
#define RCC_AHB3LPENR_QSPILPEN_Msk      (0x1UL << RCC_AHB3LPENR_QSPILPEN_Pos)      /*!< 0x00000002 */
#define RCC_AHB3LPENR_QSPILPEN          RCC_AHB3LPENR_QSPILPEN_Msk


/* RCC APB1 peripheral enable in low power mode register */

#define RCC_APB1LPENR_TIM2LPEN_Pos      (0U)
#define RCC_APB1LPENR_TIM2LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM2LPEN_Pos)      /*!< 0x00000001 */
#define RCC_APB1LPENR_TIM2LPEN          RCC_APB1LPENR_TIM2LPEN_Msk

#define RCC_APB1LPENR_TIM3LPEN_Pos      (1U)
#define RCC_APB1LPENR_TIM3LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM3LPEN_Pos)      /*!< 0x00000002 */
#define RCC_APB1LPENR_TIM3LPEN          RCC_APB1LPENR_TIM3LPEN_Msk

#define RCC_APB1LPENR_TIM4LPEN_Pos      (2U)
#define RCC_APB1LPENR_TIM4LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM4LPEN_Pos)      /*!< 0x00000004 */
#define RCC_APB1LPENR_TIM4LPEN          RCC_APB1LPENR_TIM4LPEN_Msk

#define RCC_APB1LPENR_TIM5LPEN_Pos      (3U)
#define RCC_APB1LPENR_TIM5LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM5LPEN_Pos)      /*!< 0x00000008 */
#define RCC_APB1LPENR_TIM5LPEN          RCC_APB1LPENR_TIM5LPEN_Msk

#define RCC_APB1LPENR_TIM6LPEN_Pos      (4U)
#define RCC_APB1LPENR_TIM6LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM6LPEN_Pos)      /*!< 0x00000010 */
#define RCC_APB1LPENR_TIM6LPEN          RCC_APB1LPENR_TIM6LPEN_Msk

#define RCC_APB1LPENR_TIM7LPEN_Pos      (5U)
#define RCC_APB1LPENR_TIM7LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM7LPEN_Pos)      /*!< 0x00000020 */
#define RCC_APB1LPENR_TIM7LPEN          RCC_APB1LPENR_TIM7LPEN_Msk

#define RCC_APB1LPENR_TIM12LPEN_Pos     (6U)
#define RCC_APB1LPENR_TIM12LPEN_Msk     (0x1UL << RCC_APB1LPENR_TIM12LPEN_Pos)     /*!< 0x00000040 */
#define RCC_APB1LPENR_TIM12LPEN         RCC_APB1LPENR_TIM12LPEN_Msk

#define RCC_APB1LPENR_TIM13LPEN_Pos     (7U)
#define RCC_APB1LPENR_TIM13LPEN_Msk     (0x1UL << RCC_APB1LPENR_TIM13LPEN_Pos)     /*!< 0x00000080 */
#define RCC_APB1LPENR_TIM13LPEN         RCC_APB1LPENR_TIM13LPEN_Msk

#define RCC_APB1LPENR_TIM14LPEN_Pos     (8U)
#define RCC_APB1LPENR_TIM14LPEN_Msk     (0x1UL << RCC_APB1LPENR_TIM14LPEN_Pos)     /*!< 0x00000100 */
#define RCC_APB1LPENR_TIM14LPEN         RCC_APB1LPENR_TIM14LPEN_Msk

#define RCC_APB1LPENR_WWDGLPEN_Pos      (11U)
#define RCC_APB1LPENR_WWDGLPEN_Msk      (0x1UL << RCC_APB1LPENR_WWDGLPEN_Pos)      /*!< 0x00000800 */
#define RCC_APB1LPENR_WWDGLPEN          RCC_APB1LPENR_WWDGLPEN_Msk

#define RCC_APB1LPENR_SPI2LPEN_Pos      (14U)
#define RCC_APB1LPENR_SPI2LPEN_Msk      (0x1UL << RCC_APB1LPENR_SPI2LPEN_Pos)      /*!< 0x00004000 */
#define RCC_APB1LPENR_SPI2LPEN          RCC_APB1LPENR_SPI2LPEN_Msk

#define RCC_APB1LPENR_SPI3LPEN_Pos      (15U)
#define RCC_APB1LPENR_SPI3LPEN_Msk      (0x1UL << RCC_APB1LPENR_SPI3LPEN_Pos)      /*!< 0x00008000 */
#define RCC_APB1LPENR_SPI3LPEN          RCC_APB1LPENR_SPI3LPEN_Msk

#define RCC_APB1LPENR_SPDIFRXLPEN_Pos   (16U)
#define RCC_APB1LPENR_SPDIFRXLPEN_Msk   (0x1UL << RCC_APB1LPENR_SPDIFRXLPEN_Pos)   /*!< 0x00010000 */
#define RCC_APB1LPENR_SPDIFRXLPEN       RCC_APB1LPENR_SPDIFRXLPEN_Msk

#define RCC_APB1LPENR_USART2LPEN_Pos    (17U)
#define RCC_APB1LPENR_USART2LPEN_Msk    (0x1UL << RCC_APB1LPENR_USART2LPEN_Pos)    /*!< 0x00020000 */
#define RCC_APB1LPENR_USART2LPEN        RCC_APB1LPENR_USART2LPEN_Msk

#define RCC_APB1LPENR_USART3LPEN_Pos    (18U)
#define RCC_APB1LPENR_USART3LPEN_Msk    (0x1UL << RCC_APB1LPENR_USART3LPEN_Pos)    /*!< 0x00040000 */
#define RCC_APB1LPENR_USART3LPEN        RCC_APB1LPENR_USART3LPEN_Msk

#define RCC_APB1LPENR_USART4LPEN_Pos    (19U)
#define RCC_APB1LPENR_USART4LPEN_Msk    (0x1UL << RCC_APB1LPENR_USART4LPEN_Pos)    /*!< 0x00080000 */
#define RCC_APB1LPENR_USART4LPEN        RCC_APB1LPENR_USART4LPEN_Msk

#define RCC_APB1LPENR_USART5LPEN_Pos    (20U)
#define RCC_APB1LPENR_USART5LPEN_Msk    (0x1UL << RCC_APB1LPENR_USART5LPEN_Pos)    /*!< 0x00100000 */
#define RCC_APB1LPENR_USART5LPEN        RCC_APB1LPENR_USART5LPEN_Msk

#define RCC_APB1LPENR_I2C1LPEN_Pos      (21U)
#define RCC_APB1LPENR_I2C1LPEN_Msk      (0x1UL << RCC_APB1LPENR_I2C1LPEN_Pos)      /*!< 0x00200000 */
#define RCC_APB1LPENR_I2C1LPEN          RCC_APB1LPENR_I2C1LPEN_Msk

#define RCC_APB1LPENR_I2C2LPEN_Pos      (22U)
#define RCC_APB1LPENR_I2C2LPEN_Msk      (0x1UL << RCC_APB1LPENR_I2C2LPEN_Pos)      /*!< 0x00400000 */
#define RCC_APB1LPENR_I2C2LPEN          RCC_APB1LPENR_I2C2LPEN_Msk

#define RCC_APB1LPENR_I2C3LPEN_Pos      (23U)
#define RCC_APB1LPENR_I2C3LPEN_Msk      (0x1UL << RCC_APB1LPENR_I2C3LPEN_Pos)      /*!< 0x00800000 */
#define RCC_APB1LPENR_I2C3LPEN          RCC_APB1LPENR_I2C3LPEN_Msk

#define RCC_APB1LPENR_FMPI2C1LPEN_Pos   (24U)
#define RCC_APB1LPENR_FMPI2C1LPEN_Msk   (0x1UL << RCC_APB1LPENR_FMPI2C1LPEN_Pos)   /*!< 0x01000000 */
#define RCC_APB1LPENR_FMPI2C1LPEN       RCC_APB1LPENR_FMPI2C1LPEN_Msk

#define RCC_APB1LPENR_CAN1LPEN_Pos      (25U)
#define RCC_APB1LPENR_CAN1LPEN_Msk      (0x1UL << RCC_APB1LPENR_CAN1LPEN_Pos)      /*!< 0x02000000 */
#define RCC_APB1LPENR_CAN1LPEN          RCC_APB1LPENR_CAN1LPEN_Msk

#define RCC_APB1LPENR_CAN2LPEN_Pos      (26U)
#define RCC_APB1LPENR_CAN2LPEN_Msk      (0x1UL << RCC_APB1LPENR_CAN2LPEN_Pos)      /*!< 0x04000000 */
#define RCC_APB1LPENR_CAN2LPEN          RCC_APB1LPENR_CAN2LPEN_Msk

#define RCC_APB1LPENR_CECLPEN_Pos       (27U)
#define RCC_APB1LPENR_CECLPEN_Msk       (0x1UL << RCC_APB1LPENR_CECLPEN_Pos)       /*!< 0x08000000 */
#define RCC_APB1LPENR_CECLPEN           RCC_APB1LPENR_CECLPEN_Msk

#define RCC_APB1LPENR_PWRLPEN_Pos       (28U)
#define RCC_APB1LPENR_PWRLPEN_Msk       (0x1UL << RCC_APB1LPENR_PWRLPEN_Pos)       /*!< 0x10000000 */
#define RCC_APB1LPENR_PWRLPEN           RCC_APB1LPENR_PWRLPEN_Msk

#define RCC_APB1LPENR_DACLPEN_Pos       (29U)
#define RCC_APB1LPENR_DACLPEN_Msk       (0x1UL << RCC_APB1LPENR_DACLPEN_Pos)       /*!< 0x20000000 */
#define RCC_APB1LPENR_DACLPEN           RCC_APB1LPENR_DACLPEN_Msk


/* RCC APB2 peripheral enable in low power mode register  */

#define RCC_APB2LPENR_TIM1LPEN_Pos      (0U)
#define RCC_APB2LPENR_TIM1LPEN_Msk      (0x1UL << RCC_APB2LPENR_TIM1LPEN_Pos)      /*!< 0x00000001 */
#define RCC_APB2LPENR_TIM1LPEN          RCC_APB2LPENR_TIM1LPEN_Msk

#define RCC_APB2LPENR_TIM8LPEN_Pos      (1U)
#define RCC_APB2LPENR_TIM8LPEN_Msk      (0x1UL << RCC_APB2LPENR_TIM8LPEN_Pos)      /*!< 0x00000002 */
#define RCC_APB2LPENR_TIM8LPEN          RCC_APB2LPENR_TIM8LPEN_Msk

#define RCC_APB2LPENR_USART1LPEN_Pos    (4U)
#define RCC_APB2LPENR_USART1LPEN_Msk    (0x1UL << RCC_APB2LPENR_USART1LPEN_Pos)    /*!< 0x00000010 */
#define RCC_APB2LPENR_USART1LPEN        RCC_APB2LPENR_USART1LPEN_Msk

#define RCC_APB2LPENR_USART6LPEN_Pos    (5U)
#define RCC_APB2LPENR_USART6LPEN_Msk    (0x1UL << RCC_APB2LPENR_USART6LPEN_Pos)    /*!< 0x00000020 */
#define RCC_APB2LPENR_USART6LPEN        RCC_APB2LPENR_USART6LPEN_Msk

#define RCC_APB2LPENR_ADCLPEN_Pos       (8U)
#define RCC_APB2LPENR_ADCLPEN_Msk       (0x1UL << RCC_APB2LPENR_ADCLPEN_Pos)       /*!< 0x00000100 */
#define RCC_APB2LPENR_ADCLPEN           RCC_APB2LPENR_ADCLPEN_Msk

#define RCC_APB2LPENR_SPIOLPEN_Pos      (11U)
#define RCC_APB2LPENR_SPIOLPEN_Msk      (0x1UL << RCC_APB2LPENR_SPIOLPEN_Pos)      /*!< 0x00000800 */
#define RCC_APB2LPENR_SPIOLPEN          RCC_APB2LPENR_SPIOLPEN_Msk

#define RCC_APB2LPENR_SPI1LPEN_Pos      (12U)
#define RCC_APB2LPENR_SPI1LPEN_Msk      (0x1UL << RCC_APB2LPENR_SPI1LPEN_Pos)      /*!< 0x00001000 */
#define RCC_APB2LPENR_SPI1LPEN          RCC_APB2LPENR_SPI1LPEN_Msk

#define RCC_APB2LPENR_SPI4LPEN_Pos      (13U)
#define RCC_APB2LPENR_SPI4LPEN_Msk      (0x1UL << RCC_APB2LPENR_SPI4LPEN_Pos)      /*!< 0x00002000 */
#define RCC_APB2LPENR_SPI4LPEN          RCC_APB2LPENR_SPI4LPEN_Msk

#define RCC_APB2LPENR_SYSCFGLPEN_Pos    (14U)
#define RCC_APB2LPENR_SYSCFGLPEN_Msk    (0x1UL << RCC_APB2LPENR_SYSCFGLPEN_Pos)    /*!< 0x00002000 */
#define RCC_APB2LPENR_SYSCFGLPEN        RCC_APB2LPENR_SYSCFGLPEN_Msk

#define RCC_APB2LPENR_TIM9LPEN_Pos      (16U)
#define RCC_APB2LPENR_TIM9LPEN_Msk      (0x1UL << RCC_APB2LPENR_TIM9LPEN_Pos)      /*!< 0x00010000 */
#define RCC_APB2LPENR_TIM9LPEN          RCC_APB2LPENR_TIM9LPEN_Msk

#define RCC_APB2LPENR_TIM10LPEN_Pos     (17U)
#define RCC_APB2LPENR_TIM10LPEN_Msk     (0x1UL << RCC_APB2LPENR_TIM10LPEN_Pos)     /*!< 0x00020000 */
#define RCC_APB2LPENR_TIM10LPEN         RCC_APB2LPENR_TIM10LPEN_Msk

#define RCC_APB2LPENR_TIM11LPEN_Pos     (18U)
#define RCC_APB2LPENR_TIM11LPEN_Msk     (0x1UL << RCC_APB2LPENR_TIM11LPEN_Pos)     /*!< 0x00040000 */
#define RCC_APB2LPENR_TIM11LPEN         RCC_APB2LPENR_TIM11LPEN_Msk

#define RCC_APB2LPENR_SAI1LPEN_Pos      (22U)
#define RCC_APB2LPENR_SAI1LPEN_Msk      (0x1UL << RCC_APB2LPENR_SAI1LPEN_Pos)      /*!< 0x00400000 */
#define RCC_APB2LPENR_SAI1LPEN          RCC_APB2LPENR_SAI1LPEN_Msk

#define RCC_APB2LPENR_SAI2LPEN_Pos      (23U)
#define RCC_APB2LPENR_SAI2LPEN_Msk      (0x1UL << RCC_APB2LPENR_SAI2LPEN_Pos)      /*!< 0x00800000 */
#define RCC_APB2LPENR_SAI2LPEN          RCC_APB2LPENR_SAI2LPEN_Msk


/* RCC Backup domain control register */

/* External low-speed oscillator enable */
#define RCC_BDCR_LSEON_Pos              (0U)
#define RCC_BDCR_LSEON_Msk              (0x1UL << RCC_BDCR_LSEON_Pos)              /*!< 0x00000001 */
#define RCC_BDCR_LSEON                  RCC_BDCR_LSEON_Msk

/* External low-speed oscillator ready */
#define RCC_BDCR_LSERDY_Pos             (1U)
#define RCC_BDCR_LSERDY_Msk             (0x1UL << RCC_BDCR_LSERDY_Pos)             /*!< 0x00000002 */
#define RCC_BDCR_LSERDY                 RCC_BDCR_LSERDY_Msk

/* External low-speed oscillator bypass */
#define RCC_BDCR_LSEBYP_Pos             (2U)
#define RCC_BDCR_LSEBYP_Msk             (0x1UL << RCC_BDCR_LSEBYP_Pos)             /*!< 0x00000004 */
#define RCC_BDCR_LSEBYP                 RCC_BDCR_LSEBYP_Msk

/* External low-speed oscillator mode */
#define RCC_BDCR_LSEMOD_Pos             (3U)
#define RCC_BDCR_LSEMOD_Msk             (0x1UL << RCC_BDCR_LSEMOD_Pos)             /*!< 0x00000008 */
#define RCC_BDCR_LSEMOD                 RCC_BDCR_LSEMOD_Msk

/* RTC clock source selection */
#define RCC_BDCR_RTCSEL_Pos             (8U)
#define RCC_BDCR_RTCSEL_Msk             (0x3UL << RCC_BDCR_RTCSEL_Pos)             /*!< 0x00000300 */
#define RCC_BDCR_RTCSEL                 RCC_BDCR_RTCSEL_Msk
#define RCC_BDCR_RTCSEL_0               (0x1UL << RCC_BDCR_RTCSEL_Pos)             /*!< 0x00000100 */
#define RCC_BDCR_RTCSEL_1               (0x2UL << RCC_BDCR_RTCSEL_Pos)             /*!< 0x00000200 */

#define RCC_BDCR_RTCSEL_NON             (0x00000000U << RCC_BDCR_RTCSEL_Pos)       /*!< No clock */
#define RCC_BDCR_RTCSEL_LSE             (0x00000001U << RCC_BDCR_RTCSEL_Pos)       /*!< LSE oscillator used as RTC clock */
#define RCC_BDCR_RTCSEL_LSI             (0x00000002U << RCC_BDCR_RTCSEL_Pos)       /*!< LSI oscillator used as RTC clock */
#define RCC_BDCR_RTCSEL_HSE             (0x00000003U << RCC_BDCR_RTCSEL_Pos)       /*!< HSE oscillator divided by a prescaler (selected through RTCPRE[4:0] in RCC_CFGR) used as RTC clock */

/* RTC clock enable */
#define RCC_BDCR_RTCEN_Pos              (15U)
#define RCC_BDCR_RTCEN_Msk              (0x1UL << RCC_BDCR_RTCEN_Pos)              /*!< 0x00008000 */
#define RCC_BDCR_RTCEN                  RCC_BDCR_RTCEN_Msk

/* Backup domain software reset */
#define RCC_BDCR_BDRST_Pos              (15U)
#define RCC_BDCR_BDRST_Msk              (0x1UL << RCC_BDCR_BDRST_Pos)              /*!< 0x00010000 */
#define RCC_BDCR_BDRST                  RCC_BDCR_BDRST_Msk


/* RCC clock control and status register */

/* Internal low-speed oscillator enable */
#define RCC_CSR_LSION_Pos               (0U)
#define RCC_CSR_LSION_Msk               (0x1UL << RCC_CSR_LSION_Pos)               /*!< 0x00000001 */
#define RCC_CSR_LSION                   RCC_CSR_LSION_Msk

/* Internal low-speed oscillator ready */
#define RCC_CSR_LSIRDY_Pos              (1U)
#define RCC_CSR_LSIRDY_Msk              (0x1UL << RCC_CSR_LSIRDY_Pos)              /*!< 0x00000002 */
#define RCC_CSR_LSIRDY                  RCC_CSR_LSIRDY_Msk

/* Remove reset flag */
#define RCC_CSR_RMVF_Pos                (24U)
#define RCC_CSR_RMVF_Msk                (0x1UL << RCC_CSR_RMVF_Pos)                /*!< 0x01000000 */
#define RCC_CSR_RMVF                    RCC_CSR_RMVF_Msk

/* BOR reset flag */
#define RCC_CSR_BORRSTF_Pos             (25U)
#define RCC_CSR_BORRSTF_Msk             (0x1UL << RCC_CSR_BORRSTF_Pos)             /*!< 0x02000000 */
#define RCC_CSR_BORRSTF                 RCC_CSR_BORRSTF_Msk

/* PIN reset flag */
#define RCC_CSR_PINRSTF_Pos             (26U)
#define RCC_CSR_PINRSTF_Msk             (0x1UL << RCC_CSR_PINRSTF_Pos)             /*!< 0x04000000 */
#define RCC_CSR_PINRSTF                 RCC_CSR_PINRSTF_Msk

/* POR/PDR reset flag */
#define RCC_CSR_PORRSTF_Pos             (27U)
#define RCC_CSR_PORRSTF_Msk             (0x1UL << RCC_CSR_PORRSTF_Pos)             /*!< 0x08000000 */
#define RCC_CSR_PORRSTF                 RCC_CSR_PORRSTF_Msk

/* Software reset flag */
#define RCC_CSR_SFTRSTF_Pos             (28U)
#define RCC_CSR_SFTRSTF_Msk             (0x1UL << RCC_CSR_SFTRSTF_Pos)             /*!< 0x10000000 */
#define RCC_CSR_SFTRSTF                 RCC_CSR_SFTRSTF_Msk

/* Independent watchdog reset flag */
#define RCC_CSR_IWDGRSTF_Pos            (29U)
#define RCC_CSR_IWDGRSTF_Msk            (0x1UL << RCC_CSR_IWDGRSTF_Pos)            /*!< 0x20000000 */
#define RCC_CSR_IWDGRSTF                RCC_CSR_IWDGRSTF_Msk

/* Window watchdog reset flag */
#define RCC_CSR_WWDGRSTF_Pos            (30U)
#define RCC_CSR_WWDGRSTF_Msk            (0x1UL << RCC_CSR_WWDGRSTF_Pos)            /*!< 0x40000000 */
#define RCC_CSR_WWDGRSTF                RCC_CSR_WWDGRSTF_Msk

/* Low-power reset flag */
#define RCC_CSR_LPWRRSTF_Pos            (31U)
#define RCC_CSR_LPWRRSTF_Msk            (0x1UL << RCC_CSR_LPWRRSTF_Pos)            /*!< 0x80000000 */
#define RCC_CSR_LPWRRSTF                RCC_CSR_LPWRRSTF_Msk


/* RCC spread spectrum clock generation register */
/* Modulation period. Write before setting CR[24]=PLLON bit */
#define RCC_SSCGR_MODPER_Pos            (0U)
#define RCC_SSCGR_MODPER_Msk            (0x1FFFUL << RCC_SSCGR_MODPER_Pos)         /*!< 0x00001FFF */
#define RCC_SSCGR_MODPER                RCC_SSCGR_MODPER_Msk
#define RCC_SSCGR_MODPER_0              (0x1UL << RCC_SSCGR_MODPER_Pos)            /*!< 0x00000001 */
#define RCC_SSCGR_MODPER_1              (0x2UL << RCC_SSCGR_MODPER_Pos)            /*!< 0x00000002 */
#define RCC_SSCGR_MODPER_2              (0x4UL << RCC_SSCGR_MODPER_Pos)            /*!< 0x00000004 */
#define RCC_SSCGR_MODPER_3              (0x8UL << RCC_SSCGR_MODPER_Pos)            /*!< 0x00000008 */
#define RCC_SSCGR_MODPER_4              (0x10UL << RCC_SSCGR_MODPER_Pos)           /*!< 0x00000010 */
#define RCC_SSCGR_MODPER_5              (0x20UL << RCC_SSCGR_MODPER_Pos)           /*!< 0x00000020 */
#define RCC_SSCGR_MODPER_6              (0x40UL << RCC_SSCGR_MODPER_Pos)           /*!< 0x00000040 */
#define RCC_SSCGR_MODPER_7              (0x80UL << RCC_SSCGR_MODPER_Pos)           /*!< 0x00000080 */
#define RCC_SSCGR_MODPER_8              (0x10UL << RCC_SSCGR_MODPER_Pos)           /*!< 0x00000100 */
#define RCC_SSCGR_MODPER_9              (0x20UL << RCC_SSCGR_MODPER_Pos)           /*!< 0x00000200 */
#define RCC_SSCGR_MODPER_10             (0x40UL << RCC_SSCGR_MODPER_Pos)           /*!< 0x00000400 */
#define RCC_SSCGR_MODPER_11             (0x80UL << RCC_SSCGR_MODPER_Pos)           /*!< 0x00000800 */
#define RCC_SSCGR_MODPER_12             (0x100UL << RCC_SSCGR_MODPER_Pos)          /*!< 0x00001000 */

/* Incrementation step. Write before setting CR[24]=PLLON bit */
#define RCC_SSCGR_INCSTEP_Pos           (13U)
#define RCC_SSCGR_INCSTEP_Msk           (0x7UL << RCC_SSCGR_INCSTEP_Pos)           /*!< 0x0000E000 */
#define RCC_SSCGR_INCSTEP               RCC_SSCGR_INCSTEP_Msk
#define RCC_SSCGR_INCSTEP_0             (0x1UL << RCC_SSCGR_INCSTEP_Pos)           /*!< 0x00002000 */
#define RCC_SSCGR_INCSTEP_1             (0x2UL << RCC_SSCGR_INCSTEP_Pos)           /*!< 0x00004000 */
#define RCC_SSCGR_INCSTEP_2             (0x4UL << RCC_SSCGR_INCSTEP_Pos)           /*!< 0x00008000 */

/* Spread select. Write before setting CR[24]=PLLON bit */
#define RCC_SSCGR_SPREADSEL_Pos         (30U)
#define RCC_SSCGR_SPREADSEL_Msk         (0x1UL << RCC_SSCGR_SPREADSEL_Pos)         /*!< 0x40000000 */
#define RCC_SSCGR_SPREADSEL             RCC_SSCGR_SPREADSEL_Msk

/* Spread sprectrum modulation enable */
/* Write 0 AFTER CLEARING CR[24]=PLLON bit. Write 1 BEFORE SETTING CR[24]=PLLON bit */
#define RCC_SSCGR_SSCGEN_Pos            (31U)
#define RCC_SSCGR_SSCGEN_Msk            (0x1UL << RCC_SSCGR_SSCGEN_Pos)            /*!< 0x80000000 */
#define RCC_SSCGR_SSCGEN                RCC_SSCGR_SSCGEN_Msk


/* RCC PLLI2S configuration register */
/* Division factor for audio PLL input clock */
#define RCC_PLLI2SCFGR_PLLI2SM_Pos      (0U)
#define RCC_PLLI2SCFGR_PLLI2SM_Msk      (0x3FUL << RCC_PLLI2SCFGR_PLLI2SM_Pos)     /*!< 0x0000003F */
#define RCC_PLLI2SCFGR_PLLI2SM          RCC_PLLI2SCFGR_PLLI2SM_Msk
#define RCC_PLLI2SCFGR_PLLI2SM_0        (0x1UL << RCC_PLLI2SCFGR_PLLI2SM_Pos)      /*!< 0x00000001 */
#define RCC_PLLI2SCFGR_PLLI2SM_1        (0x2UL << RCC_PLLI2SCFGR_PLLI2SM_Pos)      /*!< 0x00000002 */
#define RCC_PLLI2SCFGR_PLLI2SM_2        (0x4UL << RCC_PLLI2SCFGR_PLLI2SM_Pos)      /*!< 0x00000004 */
#define RCC_PLLI2SCFGR_PLLI2SM_3        (0x8UL << RCC_PLLI2SCFGR_PLLI2SM_Pos)      /*!< 0x00000008 */
#define RCC_PLLI2SCFGR_PLLI2SM_4        (0x10UL << RCC_PLLI2SCFGR_PLLI2SM_Pos)     /*!< 0x00000010 */
#define RCC_PLLI2SCFGR_PLLI2SM_5        (0x20UL << RCC_PLLI2SCFGR_PLLI2SM_Pos)     /*!< 0x00000020 */

/* Multiplication factor for VCO */
#define RCC_PLLI2SCFGR_PLLI2SN_Pos      (6U)
#define RCC_PLLI2SCFGR_PLLI2SN_Msk      (0x1FFUL << RCC_PLLI2SCFGR_PLLI2SN_Pos)    /*!< 0x00007FC0 */
#define RCC_PLLI2SCFGR_PLLI2SN          RCC_PLLI2SCFGR_PLLI2SN_Msk
#define RCC_PLLI2SCFGR_PLLI2SN_0        (0x1UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)      /*!< 0x00000040 */
#define RCC_PLLI2SCFGR_PLLI2SN_1        (0x2UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)      /*!< 0x00000080 */
#define RCC_PLLI2SCFGR_PLLI2SN_2        (0x4UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)      /*!< 0x00000100 */
#define RCC_PLLI2SCFGR_PLLI2SN_3        (0x8UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)      /*!< 0x00000200 */
#define RCC_PLLI2SCFGR_PLLI2SN_4        (0x10UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)     /*!< 0x00000400 */
#define RCC_PLLI2SCFGR_PLLI2SN_5        (0x20UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)     /*!< 0x00000800 */
#define RCC_PLLI2SCFGR_PLLI2SN_6        (0x40UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)     /*!< 0x00001000 */
#define RCC_PLLI2SCFGR_PLLI2SN_7        (0x80UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)     /*!< 0x00002000 */
#define RCC_PLLI2SCFGR_PLLI2SN_8        (0x100UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)    /*!< 0x00004000 */

/* PLLI2S division factor for SPDIF-Rx clock */
#define RCC_PLLI2SCFGR_PLLI2SP_Pos      (16U)
#define RCC_PLLI2SCFGR_PLLI2SP_Msk      (0x3UL << RCC_PLLI2SCFGR_PLLI2SP_Pos)      /*!< 0x00030000 */
#define RCC_PLLI2SCFGR_PLLI2SP          RCC_PLLI2SCFGR_PLLI2SP_Msk
#define RCC_PLLI2SCFGR_PLLI2SP_0        (0x1UL << RCC_PLLI2SCFGR_PLLI2SP_Pos)      /*!< 0x00010000 */
#define RCC_PLLI2SCFGR_PLLI2SP_1        (0x2UL << RCC_PLLI2SCFGR_PLLI2SP_Pos)      /*!< 0x00020000 */

/* PLLI2S division factor for SAI1 clock */
#define RCC_PLLI2SCFGR_PLLI2SQ_Pos      (24U)
#define RCC_PLLI2SCFGR_PLLI2SQ_Msk      (0xFUL << RCC_PLLI2SCFGR_PLLI2SQ_Pos)      /*!< 0x0F000000 */
#define RCC_PLLI2SCFGR_PLLI2SQ          RCC_PLLI2SCFGR_PLLI2SQ_Msk
#define RCC_PLLI2SCFGR_PLLI2SQ_0        (0x1UL << RCC_PLLI2SCFGR_PLLI2SQ_Pos)      /*!< 0x01000000 */
#define RCC_PLLI2SCFGR_PLLI2SQ_1        (0x2UL << RCC_PLLI2SCFGR_PLLI2SQ_Pos)      /*!< 0x02000000 */
#define RCC_PLLI2SCFGR_PLLI2SQ_2        (0x4UL << RCC_PLLI2SCFGR_PLLI2SQ_Pos)      /*!< 0x04000000 */
#define RCC_PLLI2SCFGR_PLLI2SQ_3        (0x8UL << RCC_PLLI2SCFGR_PLLI2SQ_Pos)      /*!< 0x08000000 */

/* PLLI2S division factor for I2S clocks */
#define RCC_PLLI2SCFGR_PLLI2SR_Pos      (28U)
#define RCC_PLLI2SCFGR_PLLI2SR_Msk      (0x7UL << RCC_PLLI2SCFGR_PLLI2SR_Pos)      /*!< 0x70000000 */
#define RCC_PLLI2SCFGR_PLLI2SR          RCC_PLLI2SCFGR_PLLI2SR_Msk
#define RCC_PLLI2SCFGR_PLLI2SR_0        (0x1UL << RCC_PLLI2SCFGR_PLLI2SR_Pos)      /*!< 0x10000000 */
#define RCC_PLLI2SCFGR_PLLI2SR_1        (0x2UL << RCC_PLLI2SCFGR_PLLI2SR_Pos)      /*!< 0x20000000 */
#define RCC_PLLI2SCFGR_PLLI2SR_2        (0x4UL << RCC_PLLI2SCFGR_PLLI2SR_Pos)      /*!< 0x40000000 */



/* RCC PLLSAI configuration register */
/* Division factor for audio PLLSAI input clock */
#define RCC_PLLSAICFGR_PLLSAIM_Pos      (0U)
#define RCC_PLLSAICFGR_PLLSAIM_Msk      (0x3FUL << RCC_PLLSAICFGR_PLLSAIM_Pos)     /*!< 0x0000003F */
#define RCC_PLLSAICFGR_PLLSAIM          RCC_PLLSAICFGR_PLLSAIM_Msk
#define RCC_PLLSAICFGR_PLLSAIM_0        (0x1UL << RCC_PLLSAICFGR_PLLSAIM_Pos)      /*!< 0x00000001 */
#define RCC_PLLSAICFGR_PLLSAIM_1        (0x2UL << RCC_PLLSAICFGR_PLLSAIM_Pos)      /*!< 0x00000002 */
#define RCC_PLLSAICFGR_PLLSAIM_2        (0x4UL << RCC_PLLSAICFGR_PLLSAIM_Pos)      /*!< 0x00000004 */
#define RCC_PLLSAICFGR_PLLSAIM_3        (0x8UL << RCC_PLLSAICFGR_PLLSAIM_Pos)      /*!< 0x00000008 */
#define RCC_PLLSAICFGR_PLLSAIM_4        (0x10UL << RCC_PLLSAICFGR_PLLSAIM_Pos)     /*!< 0x00000010 */
#define RCC_PLLSAICFGR_PLLSAIM_5        (0x20UL << RCC_PLLSAICFGR_PLLSAIM_Pos)     /*!< 0x00000020 */

/* Multiplication factor for VCO */
#define RCC_PLLSAICFGR_PLLSAIN_Pos      (6U)
#define RCC_PLLSAICFGR_PLLSAIN_Msk      (0x1FFUL << RCC_PLLSAICFGR_PLLSAIN_Pos)    /*!< 0x00007FC0 */
#define RCC_PLLSAICFGR_PLLSAIN          RCC_PLLSAICFGR_PLLSAIN_Msk
#define RCC_PLLSAICFGR_PLLSAIN_0        (0x1UL << RCC_PLLSAICFGR_PLLSAIN_Pos)      /*!< 0x00000040 */
#define RCC_PLLSAICFGR_PLLSAIN_1        (0x2UL << RCC_PLLSAICFGR_PLLSAIN_Pos)      /*!< 0x00000080 */
#define RCC_PLLSAICFGR_PLLSAIN_2        (0x4UL << RCC_PLLSAICFGR_PLLSAIN_Pos)      /*!< 0x00000100 */
#define RCC_PLLSAICFGR_PLLSAIN_3        (0x8UL << RCC_PLLSAICFGR_PLLSAIN_Pos)      /*!< 0x00000200 */
#define RCC_PLLSAICFGR_PLLSAIN_4        (0x10UL << RCC_PLLSAICFGR_PLLSAIN_Pos)     /*!< 0x00000400 */
#define RCC_PLLSAICFGR_PLLSAIN_5        (0x20UL << RCC_PLLSAICFGR_PLLSAIN_Pos)     /*!< 0x00000800 */
#define RCC_PLLSAICFGR_PLLSAIN_6        (0x40UL << RCC_PLLSAICFGR_PLLSAIN_Pos)     /*!< 0x00001000 */
#define RCC_PLLSAICFGR_PLLSAIN_7        (0x80UL << RCC_PLLSAICFGR_PLLSAIN_Pos)     /*!< 0x00002000 */
#define RCC_PLLSAICFGR_PLLSAIN_8        (0x100UL << RCC_PLLSAICFGR_PLLSAIN_Pos)    /*!< 0x00004000 */

/* PLLSAI division factor for SPDIF-Rx clock */
#define RCC_PLLSAICFGR_PLLSAIP_Pos      (16U)
#define RCC_PLLSAICFGR_PLLSAIP_Msk      (0x3UL << RCC_PLLSAICFGR_PLLSAIP_Pos)      /*!< 0x00030000 */
#define RCC_PLLSAICFGR_PLLSAIP          RCC_PLLSAICFGR_PLLSAIP_Msk
#define RCC_PLLSAICFGR_PLLSAIP_0        (0x1UL << RCC_PLLSAICFGR_PLLSAIP_Pos)      /*!< 0x00010000 */
#define RCC_PLLSAICFGR_PLLSAIP_1        (0x2UL << RCC_PLLSAICFGR_PLLSAIP_Pos)      /*!< 0x00020000 */

/* PLLSAI division factor for SAI1 clock */
#define RCC_PLLSAICFGR_PLLSAIQ_Pos      (24U)
#define RCC_PLLSAICFGR_PLLSAIQ_Msk      (0xFUL << RCC_PLLSAICFGR_PLLSAIQ_Pos)      /*!< 0x0F000000 */
#define RCC_PLLSAICFGR_PLLSAIQ          RCC_PLLSAICFGR_PLLSAIQ_Msk
#define RCC_PLLSAICFGR_PLLSAIQ_0        (0x1UL << RCC_PLLSAICFGR_PLLSAIQ_Pos)      /*!< 0x01000000 */
#define RCC_PLLSAICFGR_PLLSAIQ_1        (0x2UL << RCC_PLLSAICFGR_PLLSAIQ_Pos)      /*!< 0x02000000 */
#define RCC_PLLSAICFGR_PLLSAIQ_2        (0x4UL << RCC_PLLSAICFGR_PLLSAIQ_Pos)      /*!< 0x04000000 */
#define RCC_PLLSAICFGR_PLLSAIQ_3        (0x8UL << RCC_PLLSAICFGR_PLLSAIQ_Pos)      /*!< 0x08000000 */


/* RCC dedicated clock configuration register */
/* PLLI2S division factor for SAIs clock */
#define RCC_DCKCFGR_PLLI2SDIVQ_Pos      (0U)
#define RCC_DCKCFGR_PLLI2SDIVQ_Msk      (0x1FUL << RCC_DCKCFGR_PLLI2SDIVQ_Pos)    /*!< 0x0000001F */
#define RCC_DCKCFGR_PLLI2SDIVQ          RCC_DCKCFGR_PLLI2SDIVQ_Msk
#define RCC_DCKCFGR_PLLI2SDIVQ_0        (0x1UL << RCC_DCKCFGR_PLLI2SDIVQ_Pos)     /*!< 0x00000001 */
#define RCC_DCKCFGR_PLLI2SDIVQ_1        (0x2UL << RCC_DCKCFGR_PLLI2SDIVQ_Pos)     /*!< 0x00000002 */
#define RCC_DCKCFGR_PLLI2SDIVQ_2        (0x4UL << RCC_DCKCFGR_PLLI2SDIVQ_Pos)     /*!< 0x00000004 */
#define RCC_DCKCFGR_PLLI2SDIVQ_3        (0x8UL << RCC_DCKCFGR_PLLI2SDIVQ_Pos)     /*!< 0x00000008 */
#define RCC_DCKCFGR_PLLI2SDIVQ_4        (0x10UL << RCC_DCKCFGR_PLLI2SDIVQ_Pos)    /*!< 0x00000010 */

/* PLLSAI division factor for SAIs clock */
#define RCC_DCKCFGR_PLLSAIDIVQ_Pos      (8U)
#define RCC_DCKCFGR_PLLSAIDIVQ_Msk      (0x1FUL << RCC_DCKCFGR_PLLSAIDIVQ_Pos)    /*!< 0x00001F00 */
#define RCC_DCKCFGR_PLLSAIDIVQ          RCC_DCKCFGR_PLLSAIDIVQ_Msk
#define RCC_DCKCFGR_PLLSAIDIVQ_0        (0x1UL << RCC_DCKCFGR_PLLSAIDIVQ_Pos)     /*!< 0x00000100 */
#define RCC_DCKCFGR_PLLSAIDIVQ_1        (0x2UL << RCC_DCKCFGR_PLLSAIDIVQ_Pos)     /*!< 0x00000200 */
#define RCC_DCKCFGR_PLLSAIDIVQ_2        (0x4UL << RCC_DCKCFGR_PLLSAIDIVQ_Pos)     /*!< 0x00000400 */
#define RCC_DCKCFGR_PLLSAIDIVQ_3        (0x8UL << RCC_DCKCFGR_PLLSAIDIVQ_Pos)     /*!< 0x00000800 */
#define RCC_DCKCFGR_PLLSAIDIVQ_4        (0x10UL << RCC_DCKCFGR_PLLSAIDIVQ_Pos)    /*!< 0x00001000 */

/* SAI1 clock source selection */
#define RCC_DCKCFGR_SAI1SRC_Pos         (20U)
#define RCC_DCKCFGR_SAI1SRC_Msk         (0x3UL << RCC_DCKCFGR_SAI1SRC_Pos)        /*!< 0x00300000 */
#define RCC_DCKCFGR_SAI1SRC             RCC_DCKCFGR_SAI1SRC_Msk
#define RCC_DCKCFGR_SAI1SRC_0           (0x1UL << RCC_DCKCFGR_SAI1SRC_Pos)        /*!< 0x00100000 */
#define RCC_DCKCFGR_SAI1SRC_1           (0x2UL << RCC_DCKCFGR_SAI1SRC_Pos)        /*!< 0x00200000 */

/* SAI2 clock source selection */
#define RCC_DCKCFGR_SAI2SRC_Pos         (22U)
#define RCC_DCKCFGR_SAI2SRC_Msk         (0x3UL << RCC_DCKCFGR_SAI2SRC_Pos)        /*!< 0x00C00000 */
#define RCC_DCKCFGR_SAI2SRC             RCC_DCKCFGR_SAI2SRC_Msk
#define RCC_DCKCFGR_SAI2SRC_0           (0x1UL << RCC_DCKCFGR_SAI2SRC_Pos)        /*!< 0x00400000 */
#define RCC_DCKCFGR_SAI2SRC_1           (0x2UL << RCC_DCKCFGR_SAI2SRC_Pos)        /*!< 0x00800000 */

/* Timers clock prescalers selection */
#define RCC_DCKCFGR_TIMPRE_Pos          (24U)
#define RCC_DCKCFGR_TIMPRE_Msk          (0x1UL << RCC_DCKCFGR_TIMPRE_Pos)         /*!< 0x01000000 */
#define RCC_DCKCFGR_TIMPRE              RCC_DCKCFGR_TIMPRE_Msk

/* I2S1 clock source selection */
#define RCC_DCKCFGR_I2S1SRC_Pos         (25U)
#define RCC_DCKCFGR_I2S1SRC_Msk         (0x3UL << RCC_DCKCFGR_I2S1SRC_Pos)        /*!< 0x06000000 */
#define RCC_DCKCFGR_I2S1SRC             RCC_DCKCFGR_I2S1SRC_Msk
#define RCC_DCKCFGR_I2S1SRC_0           (0x1UL << RCC_DCKCFGR_I2S1SRC_Pos)        /*!< 0x02000000 */
#define RCC_DCKCFGR_I2S1SRC_1           (0x2UL << RCC_DCKCFGR_I2S1SRC_Pos)        /*!< 0x04000000 */

/* I2S2 clock source selection */
#define RCC_DCKCFGR_I2S2SRC_Pos         (27U)
#define RCC_DCKCFGR_I2S2SRC_Msk         (0x3UL << RCC_DCKCFGR_I2S2SRC_Pos)        /*!< 0x18000000 */
#define RCC_DCKCFGR_I2S2SRC             RCC_DCKCFGR_I2S2SRC_Msk
#define RCC_DCKCFGR_I2S2SRC_0           (0x1UL << RCC_DCKCFGR_I2S2SRC_Pos)        /*!< 0x08000000 */
#define RCC_DCKCFGR_I2S2SRC_1           (0x2UL << RCC_DCKCFGR_I2S2SRC_Pos)        /*!< 0x10000000 */


/* RCC clocks gated enable register */
/* AHB to APB1 Bridge clock enable */
#define RCC_CKGATENR_AHB2APB1_CKEN_Pos  (0U)
#define RCC_CKGATENR_AHB2APB1_CKEN_Msk  (0x1UL << RCC_CKGATENR_AHB2APB1_CKEN_Pos) /*!< 0x00000001 */
#define RCC_CKGATENR_AHB2APB1_CKEN      RCC_CKGATENR_AHB2APB1_CKEN_Msk

/* AHB to APB2 Bridge clock enable */
#define RCC_CKGATENR_AHB2APB2_CKEN_Pos  (1U)
#define RCC_CKGATENR_AHB2APB2_CKEN_Msk  (0x1UL << RCC_CKGATENR_AHB2APB2_CKEN_Pos) /*!< 0x00000002 */
#define RCC_CKGATENR_AHB2APB2_CKEN      RCC_CKGATENR_AHB2APB2_CKEN_Msk

/* Cortex M4 ETM clock enable */
#define RCC_CKGATENR_CM4DBG_CKEN_Pos    (2U)
#define RCC_CKGATENR_CM4DBG_CKEN_Msk    (0x1UL << RCC_CKGATENR_CM4DBG_CKEN_Pos)   /*!< 0x00000004 */
#define RCC_CKGATENR_CM4DBG_CKEN        RCC_CKGATENR_CM4DBG_CKEN_Msk

/* Spare clock enable */
#define RCC_CKGATENR_SPARE_CKEN_Pos     (3U)
#define RCC_CKGATENR_SPARE_CKEN_Msk     (0x1UL << RCC_CKGATENR_SPARE_CKEN_Pos)    /*!< 0x00000008 */
#define RCC_CKGATENR_SPARE_CKEN         RCC_CKGATENR_SPARE_CKEN_Msk

/* SRAM controller clock enable */
#define RCC_CKGATENR_SRAM_CKEN_Pos      (4U)
#define RCC_CKGATENR_SRAM_CKEN_Msk      (0x1UL << RCC_CKGATENR_SRAM_CKEN_Pos)     /*!< 0x00000010 */
#define RCC_CKGATENR_SRAM_CKEN          RCC_CKGATENR_SRAM_CKEN_Msk

/* Flash interface clock enable */
#define RCC_CKGATENR_FLITF_CKEN_Pos     (5U)
#define RCC_CKGATENR_FLITF_CKEN_Msk     (0x1UL << RCC_CKGATENR_FLITF_CKEN_Pos)    /*!< 0x00000020 */
#define RCC_CKGATENR_FLITF_CKEN         RCC_CKGATENR_FLITF_CKEN_Msk

/* RCC clock enable */
#define RCC_CKGATENR_RCC_CKEN_Pos       (6U)
#define RCC_CKGATENR_RCC_CKEN_Msk       (0x1UL << RCC_CKGATENR_RCC_CKEN_Pos)      /*!< 0x00000040 */
#define RCC_CKGATENR_RCC_CKEN           RCC_CKGATENR_RCC_CKEN_Msk


/* RCC dedicated clocks configuration register 2 */
/* I2C4 kernel clock source selection */
#define RCC_DCKCFGR2_FMPI2C1SEL_Pos     (22U)
#define RCC_DCKCFGR2_FMPI2C1SEL_Msk     (0x3UL << RCC_DCKCFGR2_FMPI2C1SEL_Pos)    /*!< 0x00C00000 */
#define RCC_DCKCFGR2_FMPI2C1SEL         RCC_DCKCFGR2_FMPI2C1SEL_Msk
#define RCC_DCKCFGR2_FMPI2C1SEL_0       (0x1UL << RCC_DCKCFGR2_FMPI2C1SEL_Pos)    /*!< 0x00400000 */
#define RCC_DCKCFGR2_FMPI2C1SEL_1       (0x2UL << RCC_DCKCFGR2_FMPI2C1SEL_Pos)    /*!< 0x00800000 */

#define RCC_DCKCFGR2_FMPI2C1SEL_APB     (0x0UL << RCC_DCKCFGR2_FMPI2C1SEL_Pos)    /*!< APB clock selected as FMPI2C1 clock */
#define RCC_DCKCFGR2_FMPI2C1SEL_HSI     (0x1UL << RCC_DCKCFGR2_FMPI2C1SEL_Pos)    /*!< HSI clock selected as FMPI2C1 clock */
#define RCC_DCKCFGR2_FMPI2C1SEL_SYSCLK  (0x2UL << RCC_DCKCFGR2_FMPI2C1SEL_Pos)    /*!< System clock selected as FMPI2C1 clock */

/* HDMI CEC clock source selection */
#define RCC_DCKCFGR2_CECSEL_Pos         (26U)
#define RCC_DCKCFGR2_CECSEL_Msk         (0x1UL << RCC_DCKCFGR2_CECSEL_Pos)        /*!< 0x04000000 */
#define RCC_DCKCFGR2_CECSEL             RCC_DCKCFGR2_CECSEL_Msk

/* SDIO/USBFS/HS clock selection */
#define RCC_DCKCFGR2_CK48MSEL_Pos       (27U)
#define RCC_DCKCFGR2_CK48MSEL_Msk       (0x1UL << RCC_DCKCFGR2_CK48MSEL_Pos)      /*!< 0x08000000 */
#define RCC_DCKCFGR2_CK48MSEL           RCC_DCKCFGR2_CK48MSEL_Msk

/* SDIO clock selection */
#define RCC_DCKCFGR2_SDIOSEL_Pos        (28U)
#define RCC_DCKCFGR2_SDIOSEL_Msk        (0x1UL << RCC_DCKCFGR2_SDIOSEL_Pos)       /*!< 0x10000000 */
#define RCC_DCKCFGR2_SDIOSEL            RCC_DCKCFGR2_SDIOSEL_Msk

/* SPDIF-Rx clock selection */
#define RCC_DCKCFGR2_SPDIFRXSEL_Pos     (29U)
#define RCC_DCKCFGR2_SPDIFRXSEL_Msk     (0x1UL << RCC_DCKCFGR2_SPDIFRXSEL_Pos)    /*!< 0x20000000 */
#define RCC_DCKCFGR2_SPDIFRXSEL         RCC_DCKCFGR2_SPDIFRXSEL_Msk





#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MYSTM32F446xx_H_ */
