#ifndef TAU_AVR_H_
#define TAU_AVR_H_

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#ifndef F_CPU
#define F_CPU 16000000
#endif

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>

typedef enum _GPIO_DIR {
    INPUT,
    INPUT_PULLUP,
    OUTPUT
} GPIO_DIR;

#define HIGH true
#define LOW false

typedef bool pin_status; 

// typedef enum _GPIO_

void tau_set_gpio(volatile uint8_t *port, uint8_t pin, GPIO_DIR);
void tau_write_gpio(volatile uint8_t *port, uint8_t pin, pin_status value);
#endif