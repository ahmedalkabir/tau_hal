#include <tau_uart.h>

// 8data, one stop bit and no parity
void tau_uart_init(uint32_t baudrate){
    // equation for double speed
    uint16_t calculated_baud = (F_CPU/(8*baudrate))-1;    
    UBRR0H = (uint8_t)((calculated_baud >> 8) & 0xFF);
    UBRR0L = (uint8_t)(calculated_baud & 0xFF);

    // enable double speed
    UCSR0A |= (1 << U2X0);
    // enable receiver and transmitter
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
}

void tau_uart_write_byte(const uint8_t byte){
    // wait
    while(!(UCSR0A & (1 << UDRE0)));

    // put data into buffer
    UDR0 = byte;
}

void tau_uart_write(const uint8_t *bytes, uint16_t length){
    for(uint16_t i = 0; i < length; i++){
        tau_uart_write_byte(bytes[i]);
    }
}

uint8_t tau_uart_read_byte(){
    return 0;
}