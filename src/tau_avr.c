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