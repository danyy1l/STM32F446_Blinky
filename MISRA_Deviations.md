# MISRA C:2012 Deviations Report

This document justifies the intentional deviations from the MISRA C:2012 guidelines identified by static analysis tools (e.g., Cppcheck). These deviations are strictly due to the intrinsic requirements of bare-metal programming, hardware abstraction, and memory-mapped I/O.

## 1. Rule 2.5 (Unused Macros)
- **Affected files:** `my_stm32f446xx.h`, `systick.h`
- **Justification:** The Hardware Abstraction Layer (HAL) header files map the complete peripheral structure according to the manufacturer's reference manual. It is the expected and desired behavior to define all hardware masks and bit positions for completeness, regardless of whether the current application firmware utilizes them or not.

## 2. Rule 11.4 (Casting between a pointer to object and an integer type)
- **Affected files:** `my_stm32f446xx.h`, `rcc.c`, `systick.h`, `bsp_led.c`
- **Justification:** Accessing physical microcontroller registers (Memory-Mapped I/O) inherently requires converting absolute hardware addresses (integer literals such as `0x40023800`) to pointers to `struct` types. This is the only standard and efficient way in C to interact directly with the silicon.

## 3. Rule 8.11 (When an array with external linkage is declared, its size should be explicitly specified)
- **Affected files:** `startup.c` (e.g., `extern uint32_t _sbss[];`)
- **Justification:** The linker symbols `_sbss`, `_ebss`, `_sdata`, and `_edata` represent boundary addresses of memory sections generated at link time. Their actual sizes are not known at compile time. Therefore, they must be declared as arrays of unspecified size.

## 4. Cppcheck Error: ComparePointers (Undefined Behavior)
- **Affected files:** `startup.c` (`while (dst < _ebss)`)
- **Justification:** In standard C (ISO/IEC 9899), comparing pointers that do not point to the same array object results in Undefined Behavior. However, in a bare-metal environment, the linker script guarantees that variables like `_sbss` and `_ebss` mark a contiguous block of physical SRAM. This pointer comparison is safe, intended, and strictly necessary for the C runtime environment initialization.

## 5. Rule 21.1 (Reserved identifiers for macros)
- **Affected files:** `my_stm32f446xx.h` (`__I`, `__IO`, `__O`)
- **Justification:** Macros starting with double underscores are used to align the register mapping of this project with the official ARM CMSIS convention. This deviation facilitates code portability, code reuse, and readability for other firmware engineers familiar with the ARM Cortex-M ecosystem.

## 6. Rule 8.7 (Functions and objects should not be defined with external linkage if they are referenced in only one translation unit)
- **Affected files:** `gpio.c` (`GPIO_Read`, `GPIO_Write`)
- **Justification:** These functions are part of the HAL's public API. Even if the current application code (`main.c`) does not invoke them, or invokes them from a single translation unit, their architectural design dictates that they must have external linkage so that future application layers and modules can interface with the hardware.
