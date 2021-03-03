#ifndef UART_H_
#define UART_H_

#include <tau_avr.h>
#include <stdint.h>

void tau_uart_init(uint32_t baudrate);
void tau_uart_write_byte(const uint8_t);
void tau_uart_write(const uint8_t *, uint16_t);
uint8_t tau_uart_read_byte();

#endif