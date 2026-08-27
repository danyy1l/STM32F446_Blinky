CFLAGS  ?=  -W -Wall -Wextra -Werror -Wundef -Wshadow -Wdouble-promotion \
            -Wformat-truncation -fno-common -Wconversion -std=c99 \
            -g3 -Os -ffunction-sections -fdata-sections -IInc \
            -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 \
            -MMD -MP $(EXTRA_CFLAGS)

LDFLAGS ?= -TLinkerScript_STM32_NUCLEO-F446RE.ld -nostartfiles -nostdlib \
           --specs=nano.specs -lc -lgcc -Wl,--gc-sections -Wl,-Map=$@.map

SOURCES = Src/main.c Src/startup.c

OBJECTS = $(SOURCES:.c=.o)
DEPS = $(OBJECTS:.o=.d)

.PHONY: all build flash clean misra

all: firmware.bin

build: firmware.elf

%.o: %.c
	arm-none-eabi-gcc $(CFLAGS) -c $< -o $@

firmware.elf: $(OBJECTS)
	arm-none-eabi-gcc $(OBJECTS) $(LDFLAGS) -o $@

firmware.bin: firmware.elf
	arm-none-eabi-objcopy -O binary $< $@

flash: firmware.bin
	st-flash --reset write $< 0x08000000

clean:
	rm -f firmware.elf firmware.bin *.map $(OBJECTS) $(DEPS)

misra:
	cppcheck --addon=misra.json --enable=warning,style --inconclusive --force $(SOURCES)

-include $(DEPS)
