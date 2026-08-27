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
  __IO uint32_t RRC_PLLI2SCFGR; /**< PLLI2S configuration register */
  __IO uint32_t RRC_PLLSAICFGR; /**< PLLSAI configuration register */
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

#define RCC_CR_HSION_Pos                (OU)
#define RCC_CR_HSION_Msk                (0x1UL << RCC_CR_HSION_Pos)           /*!< 0x00000001 */
#define RCC_CR_HSION                    RCC_CR_HSION_Msk

#define RCC_CR_HSIRDY_Pos               (1U)
#define RCC_CR_HSIRDY_Msk               (0x1UL << RCC_CR_HSIRDY)              /*!< 0x00000002 */
#define RCC_CR_HSIRDY                   RCC_CR_HSIRDY

#define RCC_CR_HSITRIM_Pos              (3U)
#define RCC_CR_HSITRIM_Msk              (0x1FUL << RCC_CR_HSITRIM_Pos)        /*!< 0x000000F8 */
#define RCC_CR_HSITRIM                  RCC_CR_HSITRIM_Msk
#define RCC_CR_HSITRIM_0                (0x1UL << RCC_CR_HSITRIM_Pos)         /*!< 0x00000008 */
#define RCC_CR_HSITRIM_1                (0x2UL << RCC_CR_HSITRIM_Pos)         /*!< 0x00000010 */
#define RCC_CR_HSITRIM_2                (0x4UL << RCC_CR_HSITRIM_Pos)         /*!< 0x00000020 */
#define RCC_CR_HSITRIM_3                (0x8UL << RCC_CR_HSITRIM_Pos)         /*!< 0x00000040 */
#define RCC_CR_HSITRIM_4                (0x10UL << RCC_CR_HSITRIM_Pos)        /*!< 0x00000080 */

#define RCC_CR_HSICAL_Pos               (8U)
#define RCC_CR_HSICAL_Msk               (0xFFUL << RCC_CR_HSICAL_Pos)         /*!< 0x0000FF00 */
#define RCC_CR_HSICAL                   RCC_CR_HSICAL_Msk
#define RCC_CR_HSICAL_0                 (0x1UL << RCC_CR_HSICAL_Pos)          /*!< 0x00000100 */
#define RCC_CR_HSICAL_1                 (0x2UL << RCC_CR_HSICAL_Pos)          /*!< 0x00000200 */
#define RCC_CR_HSICAL_2                 (0x4UL << RCC_CR_HSICAL_Pos)          /*!< 0x00000400 */
#define RCC_CR_HSICAL_3                 (0x8UL << RCC_CR_HSICAL_Pos)          /*!< 0x00000800 */
#define RCC_CR_HSICAL_4                 (0x10UL << RCC_CR_HSICAL_Pos)         /*!< 0x00001000 */
#define RCC_CR_HSICAL_5                 (0x2U0L << RCC_CR_HSICAL_Pos)         /*!< 0x00002000 */
#define RCC_CR_HSICAL_6                 (0x40UL << RCC_CR_HSICAL_Pos)         /*!< 0x00004000 */
#define RCC_CR_HSICAL_7                 (0x80UL << RCC_CR_HSICAL_Pos)         /*!< 0x00008000 */

#define RCC_CR_HSEON_Pos                (16U)
#define RCC_CR_HSEON_Msk                (0x1UL << RCC_CR_HSEON_Pos)           /*!< 0x00010000 */
#define RCC_CR_HSEON                    RCC_CR_HSEON_Msk

#define RCC_CR_HSERDY_Pos               (17U)
#define RCC_CR_HSERDY_Msk               (0x1UL << RCC_CR_HSERDY_Pos)          /*!< 0x00020000 */
#define RCC_CR_HSERDY                   RCC_CR_HSERDY_Msk

#define RCC_CR_HSEBYP_Pos               (18U)
#define RCC_CR_HSEBYP_Msk               (0x1UL << RCC_CR_HSEBYP_Pos)          /*!< 0x00040000 */
#define RCC_CR_HSEBYP                   RCC_CR_HSEBYP_Msk

#define RCC_CR_CSSON_Pos                (19U)
#define RCC_CR_CSSON_Msk                (0x1UL << RCC_CR_CSSON_Pos)           /*!< 0x00080000 */
#define RCC_CR_CSSON                    RCC_CR_CSSON_Msk

#define RCC_CR_PLLON_Pos                (24U)
#define RCC_CR_PLLON_Msk                (0x1UL << RCC_CR_PLLON_Pos)           /*!< 0x00100000 */
#define RCC_CR_PLLON                    RCC_CR_PLLON_Msk

#define RCC_CR_PLLRDY_Pos               (25U)
#define RCC_CR_PLLRDY_Msk               (0x1UL << RCC_CR_PLLRDY_Pos)          /*!< 0x00200000 */
#define RCC_CR_PLLRDY                   RCC_CR_PLLRDY_Msk

#define RCC_CR_PLLI2SON_Pos             (26U)
#define RCC_CR_PLLI2SON_Msk             (0x1UL << RCC_CR_PLLI2SON_Pos)        /*!< 0x00100000 */
#define RCC_CR_PLLI2SON                 RCC_CR_PLLI2SON_Msk

#define RCC_CR_PLLI2SRDY_Pos            (27U)
#define RCC_CR_PLLI2SRDY_Msk            (0x1UL << RCC_CR_PLLI2SRDY_Pos)       /*!< 0x00200000 */
#define RCC_CR_PLLI2SRDY                RCC_CR_PLLI2SRDY_Msk

#define RCC_CR_PLLSAION_Pos             (28U)
#define RCC_CR_PLLSAION_Msk             (0x1UL << RCC_CR_PLLSAION_Pos)        /*!< 0x00100000 */
#define RCC_CR_PLLSAION                 RCC_CR_PLLSAION_Msk

#define RCC_CR_PLLSAIRDY_Pos            (30U)
#define RCC_CR_PLLSAIRDY_Msk            (0x1UL << RCC_CR_PLLSAIRDY_Pos)       /*!< 0x00200000 */
#define RCC_CR_PLLSAIRDY                RCC_CR_PLLSAIRDY_Msk

/* RCC PLL configuration register */

#define RCC_PLLCFGR_PLLM_Pos            (0U)
#define RCC_PLLCFGR_PLLM_Msk            (0x3FUL << RCC_PLLCFGR_PLLM_Pos)      /*!< 0x0000003F */
#define RCC_PLLCFGR_PLLM                RCC_PLLCFGR_PLLM_Msk
#define RCC_PLLCFGR_PLLM_0              (0x1UL << RCC_PLLCFGR_PLLM_Pos)       /*!< 0x00000001 */
#define RCC_PLLCFGR_PLLM_1              (0x2UL << RCC_PLLCFGR_PLLM_Pos)       /*!< 0x00000002 */
#define RCC_PLLCFGR_PLLM_2              (0x4UL << RCC_PLLCFGR_PLLM_Pos)       /*!< 0x00000004 */
#define RCC_PLLCFGR_PLLM_3              (0x8UL << RCC_PLLCFGR_PLLM_Pos)       /*!< 0x00000008 */
#define RCC_PLLCFGR_PLLM_4              (0x10UL << RCC_PLLCFGR_PLLM_Pos)      /*!< 0x00000010 */
#define RCC_PLLCFGR_PLLM_5              (0x20UL << RCC_PLLCFGR_PLLM_Pos)      /*!< 0x00000020 */
#define RCC_PLLCFGR_PLLM_6              (0x40UL << RCC_PLLCFGR_PLLM_Pos)      /*!< 0x00000040 */

#define RCC_PLLCFGR_PLLN_Pos            (6U)
#define RCC_PLLCFGR_PLLN_Msk            (0x1FFUL << RCC_PLLCFGR_PLLN_Pos)     /*!< 0x00007FC0 */
#define RCC_PLLCFGR_PLLN                RCC_PLLCFGR_PLLN_Msk
#define RCC_PLLCFGR_PLLN_0              (0x1UL << RCC_PLLCFGR_PLLN_Pos)       /*!< 0x00000040 */
#define RCC_PLLCFGR_PLLN_1              (0x2UL << RCC_PLLCFGR_PLLN_Pos)       /*!< 0x00000080 */
#define RCC_PLLCFGR_PLLN_2              (0x4UL << RCC_PLLCFGR_PLLN_Pos)       /*!< 0x00000100 */
#define RCC_PLLCFGR_PLLN_3              (0x8UL << RCC_PLLCFGR_PLLN_Pos)       /*!< 0x00000200 */
#define RCC_PLLCFGR_PLLN_4              (0x10UL << RCC_PLLCFGR_PLLN_Pos)      /*!< 0x00000400 */
#define RCC_PLLCFGR_PLLN_5              (0x20UL << RCC_PLLCFGR_PLLN_Pos)      /*!< 0x00000800 */
#define RCC_PLLCFGR_PLLN_6              (0x40UL << RCC_PLLCFGR_PLLN_Pos)      /*!< 0x00001000 */
#define RCC_PLLCFGR_PLLN_7              (0x80UL << RCC_PLLCFGR_PLLN_Pos)      /*!< 0x00002000 */
#define RCC_PLLCFGR_PLLN_8              (0x100UL << RCC_PLLCFGR_PLLN_Pos)     /*!< 0x00004000 */

#define RCC_PLLCFGR_PLLP_Pos            (16U)
#define RCC_PLLCFGR_PLLP_Msk            (0x3UL << RCC_PLLCFGR_PLLP_Pos)       /*!< 0x00030000 */
#define RCC_PLLCFGR_PLLP                RCC_PLLCFGR_PLLP_Msk
#define RCC_PLLCFGR_PLLP_0              (0x1UL << RCC_PLLCFGR_PLLP_Pos)       /*!< 0x00010000 */
#define RCC_PLLCFGR_PLLP_1              (0x2UL << RCC_PLLCFGR_PLLP_Pos)       /*!< 0x00020000 */

#define RCC_PLLCFGR_PLLSRC_Pos          (22U)
#define RCC_PLLCFGR_PLLSRC_Msk          (0x1UL << RCC_PLLCFGR_PLLSRC_Pos)     /*!< 0x00400000 */
#define RCC_PLLCFGR_PLLSRC              RCC_PLLCFGR_PLLSRC_Msk
#define RCC_PLLCFGR_PLLSRC_HSE_Pos      (22U)
#define RCC_PLLCFGR_PLLSRC_HSE_Msk      (0x1UL << RCC_PLLCFGR_PLLSRC_HSE_Pos) /*!< 0x00400000 */
#define RCC_PLLCFGR_PLLSRC_HSE          RCC_PLLCFGR_PLLSRC_HSE_Msk
#define RCC_PLLCFGR_PLLSRC_HSI          0x00000000U

#define RCC_PLLCFGR_PLLQ_Pos            (24U)
#define RCC_PLLCFGR_PLLQ_Msk            (0xFUL << RCC_PLLCFGR_PLLQ_Pos)       /*!< 0x0F000000 */
#define RCC_PLLCFGR_PLLQ                RCC_PLLCFGR_PLLQ_Msk
#define RCC_PLLCFGR_PLLQ_0              (0x1UL << RCC_PLLCFGR_PLLQ_Pos)       /*!< 0x01000000 */
#define RCC_PLLCFGR_PLLQ_1              (0x2UL << RCC_PLLCFGR_PLLQ_Pos)       /*!< 0x02000000 */
#define RCC_PLLCFGR_PLLQ_2              (0x4UL << RCC_PLLCFGR_PLLQ_Pos)       /*!< 0x04000000 */
#define RCC_PLLCFGR_PLLQ_3              (0x8UL << RCC_PLLCFGR_PLLQ_Pos)       /*!< 0x08000000 */

#define RCC_PLLCFGR_PLLR_Pos            (28U)
#define RCC_PLLCFGR_PLLR_Msk            (0x7UL << RCC_PLLCFGR_PLLR_Pos)       /*!< 0x70000000 */
#define RCC_PLLCFGR_PLLR                RCC_PLLCFGR_PLLR_Msk
#define RCC_PLLCFGR_PLLR_0              (0x1UL << RCC_PLLCFGR_PLLR_Pos)       /*!< 0x10000000 */
#define RCC_PLLCFGR_PLLR_1              (0x2UL << RCC_PLLCFGR_PLLR_Pos)       /*!< 0x20000000 */
#define RCC_PLLCFGR_PLLR_2              (0x4UL << RCC_PLLCFGR_PLLR_Pos)       /*!< 0x40000000 */

/* RCC clock configuration register */


