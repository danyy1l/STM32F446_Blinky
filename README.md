# STM32F446 Custom HAL Blinky

A bare-metal blinky implementation for the STM32 Nucleo-F446RE dev kit. A beginner project to dive into embedded systems.

## Memory and registers

First, we need to consult the Reference Manual for the MCU (RM0390). As seen in section 2.3, Table 3, the MCU has 128kB for RAM and 512kB for flash memory (ROM). As seen in the table, the RAM section begins at 0x20000000 and flash at 0x08000000.

![STM32F446RE Memory Mapping](assets/MemoryMapping_STM32F446.png)

To know the registers we have to modify, we need to consult the Reference Manual section for GPIO ports (7.4). For example, GPIO port A (GPIOA) region begins at 0xA8000000, and from Table 1 in section 2.2.2 we know it has length of 1kB.

This is important because from the User Manual (UM1724 section 7.6) we learn that the User LD2 corresponds to I/O PA5 (pin 21), meaning it is located in GPIO port A.

## MCU boot and vector table

When the ARM MCU boots it has to read the "vector table" at the beginning of flash memory. The vector table is an array of 32-bit addresses of interrupt handlers, where first 16 entries are reserved and common to all ARM MCUs. The rest are specific to the MCU, as they are interrupt handlers for peripherals.

Vector table for STM32F446 is in Table 38 and as seen, we have 16 standard and 97 board-specific entries.

Every entry in the vector table contains the address of an interrupt handler, i.e a function that executes when a hardware interrupt ocurrs (IRQ). The first and second entries are exceptions, as those two values are: an initial stack pointer and an address of the boot function to execute (firmware entry point).

Therefore, we need to make sure the firmware is composed in a way that the second 32-bit value in the ROM contains the address of the boot function.

## Firmware test

Now, we can create a main file, that specifies our boot function, which will initially do nothing (infinite loop), and specify a vector table containing 16 standard entries and 91 board-specific entries.

```c
//Startup code
__attribute__((naked, noreturn)) void _reset(void){
    for(;;) (void) 0;
}

extern void _estack(void); // Defined in linker script

__attribute__((section(".vectors"))) void(*const tab[16 + 97])(void) = {
    _estack, _reset
};
```

Here _reset() is the reset handler. The `void (*const tab[16 + 97])(void)` expression means to define an array of 16 + 97 pointers to functions that return nothing (void) and take no arguments (void). Each function should be an IRQ handler.

The vector table defined by this is put in a section called .vectors, that we will tell in the linker script to be put at the beginning of the firmware, i.e at the beginning of the flash memory.

### Compilation

Compiling this code with the following command:

```bash
$ arm-none-eabi-gcc -mcpu=cortex-m4 main.c -c
```

We obtain an object file `main.o`, containing the minimal firmware. If we run the `objdump` command we will see the sections contained:

```bash
$ arm-none-eabi-objdump -h main.o

main.o:     file format elf32-littlearm

Sections:
Idx Name          Size      VMA       LMA       File off  Algn
  0 .text         00000002  00000000  00000000  00000034  2**1
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
  1 .data         00000000  00000000  00000000  00000036  2**0
                  CONTENTS, ALLOC, LOAD, DATA
  2 .bss          00000000  00000000  00000000  00000036  2**0
                  ALLOC
  3 .vectors      000001ac  00000000  00000000  00000038  2**2
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA
  4 .comment      00000012  00000000  00000000  000001e4  2**0
                  CONTENTS, READONLY
  5 .ARM.attributes 0000002e  00000000  00000000  000001f6  2**0
                  CONTENTS, READONLY
```

As seen in the result, the VMA/LMA addresses are set to 0, meaning our object file is not a firmware because it lacks the information where those sections should be loaded in the address space.

The section .text contains firmware code, right now, the _reset() function. There are also an empty .data and .bss sections. The firmware will be copied to flash, but the data section should reside in RAM. Therefore _reset() must copy the contents of .data to RAM, and also write zeroes to the whole .bss section When compiling firmware, the output is an ELF file with sections: .text, .data, .rodata, .bss and others. The linker script maps ELF sections to different memory regions of the microcontroller, basically defining the firmware memory layout. We make the following script:

```c
ENTRY(_reset):
```

This line tells the linker the value of the entry point in the ELF header, basically a duplicate of what a vector table has. This is an aid for debuggers to set a breakpoint at the beginning.

```c
MEMORY {
  /* f446 memory mapping */
  FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 512K
  RAM(rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}
```

This tells the linker the memory sections in the address space, their addresses and length.

```c
_estack = ORIGIN(RAM) + LENGTH(RAM);
```

This creates a symbol _estack(end stack) with value at the very end of the RAM. As the stack grows downwards, this is our initial stack value.

```c
.vectors  : { KEEP(*(.vectors)) } > FLASH
  .text     : { *(.text*) }         > FLASH
  .rodata   : { *(.rodata*) }       > FLASH
```

This lines tell the linker to put vectors table on flash first, followed by text section and read-only data section.

Next, we tell the linker the instructions for .data and .bss sections.

```c
.data     : {
    _sdata = .; /* .data section start */
    *(.first_data)
    *(.data SORT(.data.*))
    _edata = .; /* .data section end */
  } > RAM AT > FLASH
  _sidata = LOADADDR(.data);
```

Here we do various things: first, we create a symbol called _sdata and we asign the exact memory address where we are (the dot symbol is the Location Counter). The asterisk means "in every object file (.o)", so in the second and third line we are taking every symbol called .first_data, every .data section and every variation in the form .data.* sorted alphabetically from the C files and writing them at this address. And finally, we define the end of the section with the symbol _edata.

The following line `> RAM AT > FLASH` is doing two things, first, `> RAM` tells the compiler that when it tries to read or modify data, to seek for it in RAM. `AT > FLASH` tells the flashing tool to write the initial values in flash when it flashes the .bin file in the microcontroller.

Lastly, `_sidata = LOADARR(.data)` calculates the physical address in flash of the beginning of the .data section and saves it into the symbol (Source Initial Data). This will be used in the startup script.

Lastly, for the .bss section:

```c
.bss      : {
    _sbss = .;  /* .bss section start */
    *(.bss SORT(.bss.*) COMMON)
    _ebss = .;  /* .bss section end */
  } > RAM
```

As earlier, we declare the bss section start and assign the address to the symbol _sbss. Same as earlier, we take every symbol named .bss or any variation in the form .bss* and write them in this area. The COMMON keyword also adds the special section COMMON that the compiler creates if any different files declare a variable with the same name. Finally, we save the final address in _ebss and reserve its space in RAM, therefore this section will not be in our .bin file.

## Startup script

Now, we need a software routine that executes immediately after a Reset in our MCU. The reason we need it is to initialize our CRT and meet the hardware architecture specifications. So, our startup code will need to write the value of the stack pointer to the first 32-bit word in the address 0x00000000 (mapped to flash 0x08000000) and the second word to have the address of the Reset_Handler.

It will also need to copy the .data section to SRAM (VMA) to allow read/write operations and to zero-fill the .bss section. For this, we rename our main.c file to startup.c and make slight changes.

```c
/* Import of Linker Script symbols */
extern long _sbss, _ebss, _sdata, _edata, _sidata;

/* Declaration of _estack as a function is standard in firmware, as it avoids
 * referencing with & or explicitly casting it */
extern void _estack(void);

/* Import of main function */
extern int main(void);

__attribute__((naked, noreturn)) void _reset(void) {
  for (long *dst = &_sbss; dst < &_ebss; dst++)
    *dst = 0;
  for (long *dst = &_sdata, *src = &_sidata; dst < &_edata;)
    *dst++ = *src++;

  main();

  /* Infinite loop in case main returns */
  while (1)
    (void)0;
}

// 16 standard and 97 STM32-specific handlers
__attribute__((section(".vectors"))) void (*const tab[16 + 97])(void) = {
    _estack, /* Offset 0x00: Initial main stack pointer (MSP) */
    _reset   /* Offset 0x04: Reset_Handler */
             /*  */
};
```
The compiler attributes naked and noreturn serve to instruct the compiler to: first, omit generating the PUSH and POP operations previous to the function, as when calling _reset, the SP just was initialized by hardware and is unsafe to use; and second, indicate that the execution will never leave this function (infinite loop), allowing the compiler to optimize code by removing the return instruction (BX LR).

Next, we initialize the sections as required by architecture ARM Cortex-M. The .bss section is zero-filled, the .data section is block copied from Flash VMA to RAM LMA.

Lastly, we create the vector table, making sure that the first entry is the stack pointer (SP) and the second the Reset_Handler.

# Blinky

After all this setup, we can finally begin to write our main function. For this project we will write our own bare-metal library with custom structs, macros and bit handling functions.

First, we begin by writing our own library handling the memory addresses. In a new `my_stm32f446xx.h` file, we begin to write some code.

We know a couple of our needs:

* RCC struct
* GPIOx struct (one for each GPIO port A-H)
* Base addresses for each struct
* Pin handling functions (GPIO_write_pin for example)

So, I begin writing a general code structure:

```c
#define __I volatile const /**< Defines read permission */
#define __IO volatile      /**< Defines read / write permissions */
#define __O volatile       /**< Defines write permission */

typedef struct {

} RCC_typedef;

#define RCC_BASE 0x00000000

#define RCC (RCC_typedef *)RCC_BASE

typedef struct {

} GPIO_typedef;

#define GPIOA_BASE 0x00000000
#define GPIOB_BASE 0x00000000
#define GPIOC_BASE 0x00000000
#define GPIOD_BASE 0x00000000
#define GPIOE_BASE 0x00000000
#define GPIOF_BASE 0x00000000
#define GPIOG_BASE 0x00000000
#define GPIOH_BASE 0x00000000

#define GPIOA (GPIO_typedef *)GPIOA_BASE
#define GPIOB (GPIO_typedef *)GPIOB_BASE
#define GPIOC (GPIO_typedef *)GPIOC_BASE
#define GPIOD (GPIO_typedef *)GPIOD_BASE
#define GPIOE (GPIO_typedef *)GPIOE_BASE
#define GPIOF (GPIO_typedef *)GPIOF_BASE
#define GPIOG (GPIO_typedef *)GPIOG_BASE
#define GPIOH (GPIO_typedef *)GPIOH_BASE
```

First, we need to know where the LED is located in the board. User Manual (UM1724) section 7.6 tells us: "User LD2: the green LED is a user LED connected to ARDUINO® signal D13 corresponding to STM32 I/O PA5 (pin 21)". Therefore, we know know that we need to access GPIO port A, pin 5.

The steps for initializing a pin are:

- Enabling the clock for the port.
- Setting the initial state of the pin.
- Defining its direction (Input or Output).
- Configuring the output type (Push-Pull or Drain).
- Configuring port output speed register (Unnecessary for this project).
- Configuring pull-up/pull-down register (Unnecessary for this project).



Next, we need to fill the struct with all the registers indicated by the Reference Manual (RM0390). For example, this would be the RCC struct.
```c
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
```

Once filled the structs, we need to map their macros to the corresponding memory addresses. We can get the memory addresses from Section 2.2.2 Table 1. STM32F446xx register boundary addresses:

![Memory Addresses](assets/RCC_GPIO_mem.png)

```c
#define PERIPH_BASE 0x40000000UL

#define APB1PERIPH_BASE PERIPH_BASE
#define APB2PERIPH_BASE (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE (PERIPH_BASE + 0x10000000UL)
#define AHB3PERIPH_BASE (PERIPH_BASE + 0x20000000UL)

#define RCC_BASE (AHB1PERIPH_BASE + 0x00003800UL)

#define GPIOA_BASE (AHB1PERIPH_BASE)
#define GPIOB_BASE (AHB1PERIPH_BASE + 0x00000400UL)
#define GPIOC_BASE (AHB1PERIPH_BASE + 0x00000800UL)
#define GPIOD_BASE (AHB1PERIPH_BASE + 0x00000C00UL)
#define GPIOE_BASE (AHB1PERIPH_BASE + 0x00001000UL)
#define GPIOF_BASE (AHB1PERIPH_BASE + 0x00001400UL)
#define GPIOG_BASE (AHB1PERIPH_BASE + 0x00001800UL)
#define GPIOH_BASE (AHB1PERIPH_BASE + 0x00001C00UL)
```

Next, we have to create macros for the bits for each corresponding register. We will follow the same pattern as the manufacturer, where we create a position macro, representing which bit in the register we are addressing, a mask macro, where we shift the value to its desired position in the register to clear bits without varying the others, and the base macro, to toggle a specific bit. For example:

```c
#define RCC_CR_HSEON_Pos        (16U)
#define RCC_CR_HSEON_Msk        (0x1UL << RCC_CR_HSEON_Pos)
#define RCC_CR_HSEON            RCC_CR_HSEON_Msk

//For bigger bit fields we do as follows
#define RCC_CR_HSITRIM_Pos      (3U)
#define RCC_CR_HSITRIM_Msk      (0x1FUL << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM          RCC_CR_HSITRIM_Msk
#define RCC_CR_HSITRIM_0        (0x1UL << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM_1        (0x2UL << RCC_CR_HSITRIM_Pos)
```

This is a tedious and hard process, as we need to map all the registers needed for the project, and define macros for each bit. In this case, I have mapped all the registers and bits for RCC and GPIO peripherals. I will keep extending this header file in future projects. Once this is done, theoretically we could create our bare-metal main.c handling all the registers to blink the LED. 

But let's take it a step further. We can get away from the hardware by creating a small Hardware Abstraction Layer, and abstract all the register handling into functions. For example, for the GPIO handling we create the following structure and functions:

```c
#define GPIO_PIN_MAX 15U

typedef enum {
  GPIO_PIN_RESET = 0U,              /**!< Pin is connected to GND */
  GPIO_PIN_SET = 1U                 /**!< Pin is connected to VDD */
} GPIO_PinState_t;

typedef enum {
  GPIO_MODE_INPUT = 0b00U,          /**!< Input (reset state) */
  GPIO_MODE_OUTPUT = 0b01U,         /**!< General purpose output mode */
  GPIO_MODE_ALT_FUNCTION = 0b10U,   /**!< Alternate function mode */
  GPIO_MODE_ANALOG = 0b11U          /**!< Analog mode */ 
} GPIO_Mode_t;

void GPIO_SetMode(GPIO_typedef *port, uint8_t pin, GPIO_Mode_t mode);

void GPIO_Write(GPIO_typedef *port, uint8_t pin, GPIO_PinState_t state);

void GPIO_Toggle(GPIO_typedef *port, uint8_t pin);

GPIO_PinState_t GPIO_Read(const GPIO_typedef *port, uint8_t pin);
```

This way, the user doesn't need to know the exact memory addresses to read the current value in port B, pin 5, they can just use the provided function.

For this project, we will need to create a HAL for all the needed peripherals: GPIO, RCC and SysTick, which will be our timing control.

And as a further abstraction, I have created a Board Support Package, to allow the user to just use the LED handling functions. This way, they do not have to worry about GPIO peripherals, RCC or flipping bits with logical operators, and instead they can just init and toggle the light.

Lastly, I have implemented a Makefile rule for cppcheck to check for MISRA-C 2012 compliance within the project.

## References

This project was built from the ground up by studying microcontroller architecture, official documentation, and community resources. The following materials were instrumental in understanding the bare-metal boot process, memory mapping, and safe register manipulation:

*   **[STM32F446xx Reference Manual (RM0390)](https://www.st.com/resource/en/reference_manual/rm0390-stm32f446xx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf):** The ultimate source of truth for the microcontroller's memory map, boot configuration (Section 2.3), and GPIO register specifications.
*   **[CMSIS Device Headers (STM32F4)](https://github.com/STMicroelectronics/cmsis-device-f4/tree/master/Include):** Official hardware abstraction headers (`stm32f446xx.h`) provided by STMicroelectronics, used to implement safe bitmasking (Read-Modify-Write patterns).
*   **[Bare Metal Programming Guide by cpq](https://github.com/cpq/bare-metal-programming-guide):** An excellent and comprehensive repository detailing the bare-metal toolchain, linker scripts, and startup code fundamentals.
*   **[Bare Metal Blink on STM32 by J. Chisholm](https://jchisholm204.github.io/posts/baremetal_blink/):** A practical tutorial that served as a reference for structuring the initial minimal bare-metal implementation.
*   **[ARM GCC Toolchain Documentation](https://gcc.gnu.org/onlinedocs/gcc/ARM-Options.html):** Used to understand compiler flags (`-ffunction-sections`, `-nostartfiles`, `-mfloat-abi`) and linker behavior for embedded systems.

