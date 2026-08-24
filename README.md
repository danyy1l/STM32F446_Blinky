# STM32F446 Button Controlled Blinky

After implementing the regular Blinky project, I decided to make a simple extension. The blinking speed (or code written delay) should now be controlled by the pressing of the user button, so each time the button is pressed, the blinking would go faster, until a certain point, where it would reset to the default speed.

For this extension, we now need not only the LD2 pin, but also the GPIO pin linked to the user button.

As a last comment, I have implemented a very simple FSM for controlling the speed, implementing it with the switch pattern.

As in the regular blinky, we begin by configuring the clock and the GPIO registers.

```
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable clock for PORT A
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; // Enable clock for PORT C

  GPIOA->MODER &= ~GPIO_MODER_MODE5; // Clear mode bits
  GPIOA->MODER |=
      GPIO_MODER_MODE5_0; // Activate bit 0, as 01 is output mode for moder
  GPIOA->OTYPER &= ~GPIO_OTYPER_OT5; // Ensure port is in push-pull state
                                     // instead of open drain
  GPIOA->OSPEEDR &=
      ~GPIO_OSPEEDER_OSPEEDR5; // Clear speed bits to set starting low speed

  GPIOC->MODER &= ~GPIO_MODER_MODE13;
  GPIOC->OTYPER &= ~GPIO_OTYPER_OT13;
  GPIOC->OSPEEDR &=
      ~GPIO_OSPEEDER_OSPEEDR13; // Clear speed bits to set starting low speed
```

Next, for the switch pattern we will need an enumeration, through which we can link each state to a value of the enum.

```
typedef enum { VERY_SLOW = 0, SLOW, MEDIUM, FAST, TURBO } Blink_Speed;
```

Now we can begin implementing the functionality. Basically, what we need to do is constantly read if the user button has been pressed. If it has not been pressed, the blinking continues at the same rate (controlled by a delay variable); if it has, we will need to vary the tick delay, using the switch statement that sets its value:

```
  Blink_Speed current_speed = VERY_SLOW;
  volatile uint32_t count = 1000000U;
  volatile uint8_t button_pressed = 0;
  uint32_t ticks = 0;

  while (1) {
    if ((GPIOC->IDR & GPIO_IDR_ID13) == 0) {
      if (button_pressed == 0) {
        button_pressed = 1;

        ++current_speed;
        if (current_speed > TURBO)
          current_speed = VERY_SLOW;

        switch (current_speed) {
        case VERY_SLOW:
          count = 1000000U;
          break;
        case SLOW:
          count = 500000U;
          break;
        case MEDIUM:
          count = 250000U;
          break;
        case FAST:
          count = 125000U;
          break;
        case TURBO:
          count = 50000U;
          break;
        }
      }
    } else {
      button_pressed = 0;
    }

    ++ticks;
    if (ticks >= count) {
      GPIOA->ODR ^= GPIO_ODR_OD5;
      ticks = 0;
    }
  }
```

Lastly, we can flash the firmware into the board and verify it works correctly. As a final comment, the blinking has been implemented using the tick variable and blinking after the tick counter has passed. This has been the main choice because if it has been done with any kind of loop (for example `while(count--){}`) it would have caused a busy wait (spin waiting), therefore not reading the button presses while active.

As a future extension, the button press should trigger a hardware interrupt, and the speed change could be implemented into the IRQ handler. This will be done after further learning of the NVIC.
