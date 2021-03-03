#include "tau_avr.h"
#include "tau_i2c.h"
#include <util/delay.h>

int main(){

    // init i2c communication
    tau_set_gpio(&DDRB, 5, OUTPUT);
    while(1){
        tau_write_gpio(&PORTB, 5, HIGH);
        _delay_ms(500);
        tau_write_gpio(&PORTB, 5, LOW);
        _delay_ms(500);
    }
    return 0;
}