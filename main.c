#include "tau_avr.h"
#include "tau_uart.h"
#include <util/delay.h>

int main(){

    // init i2c communication
    tau_uart_init(9600);
    tau_uart_write((uint8_t *)"it works, nice\n", 16);
    while(1){

    }
    return 0;
}