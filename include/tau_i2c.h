#ifndef TAU_I2C_H_
#define TAU_I2C_H_

typedef enum _I2C_SPEED {
    STANDARD_MODE,
    FAST_MODE
} I2C_SPEED;

void i2c_init(I2C_SPEED);
void i2c_write();
void i2c_read();

#endif