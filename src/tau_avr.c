#include <tau_avr.h>

void tau_set_gpio(volatile uint8_t *port, uint8_t pin, GPIO_DIR pin_dir){
    if(pin_dir == INPUT){
        *port &= ~(1 << pin);
    }else if(pin_dir == INPUT_PULLUP){
        *port &= ~(1 << pin);
        *(port+1) |= (1 << pin);
    }else if(pin_dir == OUTPUT){
        *port |= (1 << pin);   
    }
}

void tau_write_gpio(volatile uint8_t *port, uint8_t pin, pin_status value){
    if(value == HIGH){
        *(port+1) |= (1 << pin);
    }else if(value == LOW){
        *(port+1) &= ~(1 << pin);
    }
}

pin_status tau_read_gpio(volatile uint8_t *port, uint8_t pin){
    return (pin_status)(*(port-1) & (1 << pin));   
}

void system_clock_init(){
    TCCR0A |= (1 << WGM01); // CTC mode
    TCCR0B |= (1 << CS00) | (1 << CS01); // CPU_CLOCK / 64
    TIMSK0 |= (1 << OCIE0A);  // enable compare match A interrupt
    // as it will be called every 1ms
    TCNT0 = 0;
    OCR0A = 249;
}