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

#define GPIO_A &DDRA
#define GPIO_B &DDRB
#define GPIO_C &DDRC
#define GPIO_D &DDRD
#define GPIO_E &DDRE

typedef bool pin_status; 

// typedef enum _GPIO_

void tau_set_gpio(volatile uint8_t *port, uint8_t pin, GPIO_DIR);
void tau_write_gpio(volatile uint8_t *port, uint8_t pin, pin_status value);
pin_status tau_read_gpio(volatile uint8_t *port, uint8_t pin);

// it will enable timer0 to be used with QuarkTS 
void system_clock_init();
#endif