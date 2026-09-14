#ifndef UTILS_H
#define UTILS_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @brief Hardware assertion macro for validation during execution
 * 
 * Evaluates a conditional expression, if it were false, halts the MCU safely.
 * During debug, a failure to assert, creates an ARM Cortex-M Hardware Breakpoint 
 * followed by an infinite loop, allowing the debugger to pause the execution exactly in the error.
 *
 * @param expr Logical expression to be test
 */

#ifdef NDEBUG
#define HW_ASSERT(expr) (void)0
#else
#define HW_ASSERT(expr)                                  \
  do {                                                   \
    if (!(expr)) {                                       \
      /* Cortex-M instruction for Hardware Breakpoint */ \
      __asm volatile("bkpt #0");                         \
      /* Infinite loop for program stop */               \
      for (;;) {                                         \
      }                                                  \
    }                                                    \
  } while (0)
#endif /* NDEBUG */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __UTILS_H */
