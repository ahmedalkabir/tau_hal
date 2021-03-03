target := tau_hal
CC= avr-gcc
CXX=avr-gcc
BUILD_DIR ?= build
ELF = $(addsuffix .elf, $(BUILD_DIR)/$(target))
HEX = $(addsuffix .hex, $(ELF))
MCU ?= atmega328p
FREQ ?= 16000000
F_CPU = FREQ
COM ?= COM10
CFLAGS += -mmcu=$(MCU) -DF_CPU=$(FREQ) -Wall -Wextra -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects

LIB_SRC = src/
MAIN_OBJS = $(patsubst %.c, %.o, $(wildcard *.c))
LIB_OBJS = $(patsubst %.c, %.o, $(wildcard src/*.c))

all: $(ELF)

$(ELF): $(MAIN_OBJS) $(LIB_OBJS)
	$(CC) $(CFLAGS) -I./include $^ -o $@
	avr-objcopy -O ihex -R .eeprom $@ $(addsuffix .hex, $@)
	avr-size $@

%.o: %.c
	$(CC) $(CFLAGS) -c -I./include $^ -o $@

flash: $(ELF)
	avrdude -p $(MCU) -c arduino -P $(COM) -b 115200 -D -U flash:w:$(HEX):i

clean:
	rm -f *.o  *.d  $(LIB_SRC)/*.o $(LIB_SRC)/*.d *.elf

.PHONY: all clean
