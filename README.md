# STM32F446 Custom HAL Blinky

A bare-metal blinky implementation for the STM32 Nucleo-F446RE dev kit. A beginner project to dive into embedded systems.
=======
After experimenting with GPIO and its registers, the logical step up to this project is to create our own custom HAL for handling the memory addresses. As a first step, we can basically delete the contents of the Inc/ folder, as we will be creating our own header file. Next, we can begin writing our header file. In a new `my_stm32f446xx.h` file, we begin to write some code.

Having implemented the blinky with the HAL provided by ST Microelectronics, we know a couple of our needs:

## Memory and registers
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

## MCU boot and vector table
=======
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

<<<<<<< HEAD
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
=======
#define GPIOA (GPIO_typedef *)GPIOA_BASE
#define GPIOB (GPIO_typedef *)GPIOB_BASE
#define GPIOC (GPIO_typedef *)GPIOC_BASE
#define GPIOD (GPIO_typedef *)GPIOD_BASE
#define GPIOE (GPIO_typedef *)GPIOE_BASE
#define GPIOF (GPIO_typedef *)GPIOF_BASE
#define GPIOG (GPIO_typedef *)GPIOG_BASE
#define GPIOH (GPIO_typedef *)GPIOH_BASE
```

Next, we need to fill the struct with all the registers indicated by the Reference Manual (RM0390). For example, this would be the RCC struct.

The vector table defined with this is put in a section called .vectors, that we will tell in the linker script to be put at the beginning of the firmware, i.e at the beginning of the flash memory.

### Compilation

Compiling this code with the following command:

```bash
$ arm-none-eabi-gcc -mcpu=cortex-m4 main.c -c
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

```bash
$ arm-none-eabi-objdump -h main.o
=======
![STM32F446xx register boundary addresses](assets/RCC_GPIO_mem.png)
>>>>>>> 3c9c18342aaebdf34179b429e573618409c8c436

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

<<<<<<< HEAD
```bash
ENTRY(_reset):
```

This line tells the linker the value of the entry point in the ELF header, basically a duplicate of what a vector table has. This is an aid for debuggers to set a breakpoint at the beginning.

```bash
MEMORY {
  /* f446 memory mapping */
  FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 512K
  RAM(rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}
```

This tells the linker the memory sections in the address space, their addresses and length.

```bash
_estack = ORIGIN(RAM) + LENGTH(RAM);
```

This creates a symbol _estack (end stack) with value at the very end of the RAM. As the stack grows downwards, this is our initial stack value.

```bash
.vectors  : { KEEP(*(.vectors)) } > FLASH
  .text     : { *(.text*) }         > FLASH
  .rodata   : { *(.rodata*) }       > FLASH
```

This lines tell the linker to put vectors table on flash first, followed by text section and read-only data section.

Next, we tell the linker the instructions for .data and .bss sections.

```bash
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

```bash
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

After all this setup, we can finally begin to write our main function. First, I have used the provided libraries by ST Microelectronics, found in Inc/. Once this is done, we will write our own bare-metal library with custom structs, macros and bit handling functions.

First, we need to know where the LED is located in the board. User Manual (UM1724) section 7.6 tells us: "User LD2: the green LED is a user LED connected to ARDUINO® signal D13 corresponding to STM32 I/O PA5 (pin 21)". Therefore, we know know that we need to access GPIO port A, pin 5.

The following steps are:
 * Enabling the clock for this port.
 * Setting the initial state of the pin.
 * Defining its direction (Input or Output).
 * Configuring the output type (Push-Pull or Drain).
 * Configuring port output speed register (Unnecessary for this project).
 * Configuring pull-up/pull-down register (Unnecessary for this project).

For the LD2 pin we write this code:
```c
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable clock for PORT A
  GPIOA->MODER &= ~GPIO_MODER_MODE5; // Clear mode bits
  GPIOA->MODER |= GPIO_MODER_MODE5_0; // Activate bit 0, as 01 is output mode for moder
  GPIOA->OTYPER &= ~GPIO_OTYPER_OT5; // Ensure port is in push-pull state instead of open drain
  GPIOA->OSPEEDR &= ~GPIO_OSPEEDER_OSPEEDR5; // Clear speed bits to set starting low speed
```

Now, we can begin to write the main loop. The functionality is basic: toggle the register output value between 1 and 0, and between each toggle, delay the clock so the blink is noticeable.

```c
while(1){
  volatile uint32_t count = 1000000;

  GPIOA->ODR ^= GPIO_ODR_OD5;

  while(count--) {} 
}

return 0; // Needed because of main function 'int' signature
```

That's it! Our main program now compile without problems and when flashed to the board, the LED will blink.

With the following Makefile grabbed from the guide repository:
```bash
CFLAGS  ?=  -W -Wall -Wextra -Werror -Wundef -Wshadow -Wdouble-promotion \
            -Wformat-truncation -fno-common -Wconversion \
            -g3 -Os -ffunction-sections -fdata-sections -IInc \
            -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 $(EXTRA_CFLAGS)

LDFLAGS ?= -TLinkerScript_STM32_NUCLEO-F446RE.ld -nostartfiles -nostdlib --specs nano.specs -lc -lgcc -Wl,--gc-sections -Wl,-Map=$@.map

SOURCES = Src/main.c Src/startup.c

all: firmware.bin

build: firmware.elf

firmware.elf: $(SOURCES)
	arm-none-eabi-gcc $(SOURCES) $(CFLAGS) $(LDFLAGS) -o $@

firmware.bin: firmware.elf
	arm-none-eabi-objcopy -O binary $< $@

flash: firmware.bin
	st-flash --reset write $< 0x08000000
```

And finally the Blinky is complete!

## References

This project was built from the ground up by studying microcontroller architecture, official documentation, and community resources. The following materials were instrumental in understanding the bare-metal boot process, memory mapping, and safe register manipulation:

*   **[STM32F446xx Reference Manual (RM0390)](https://www.st.com/resource/en/reference_manual/rm0390-stm32f446xx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf):** The ultimate source of truth for the microcontroller's memory map, boot configuration (Section 2.3), and GPIO register specifications.
*   **[CMSIS Device Headers (STM32F4)](https://github.com/STMicroelectronics/cmsis-device-f4/tree/master/Include):** Official hardware abstraction headers (`stm32f446xx.h`) provided by STMicroelectronics, used to implement safe bitmasking (Read-Modify-Write patterns).
*   **[Bare Metal Programming Guide by cpq](https://github.com/cpq/bare-metal-programming-guide):** An excellent and comprehensive repository detailing the bare-metal toolchain, linker scripts, and startup code fundamentals.
*   **[Bare Metal Blink on STM32 by J. Chisholm](https://jchisholm204.github.io/posts/baremetal_blink/):** A practical tutorial that served as a reference for structuring the initial minimal bare-metal implementation.
*   **[ARM GCC Toolchain Documentation](https://gcc.gnu.org/onlinedocs/gcc/ARM-Options.html):** Used to understand compiler flags (`-ffunction-sections`, `-nostartfiles`, `-mfloat-abi`) and linker behavior for embedded systems.
=======
//For bigger bit fields we do as follows

#define RCC_CR_HSITRIM_Pos      (3U)
#define RCC_CR_HSITRIM_Msk      (0x1FUL << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSITRIM          RCC_CR_HSITRIM_Msk
```
