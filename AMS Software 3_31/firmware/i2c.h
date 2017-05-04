#ifndef I2C_H
#define I2C_H

// C standard libraries
#include <stdint.h>
#include <stdbool.h>

extern volatile bool bypass_flag;
extern volatile bool panic_flag;
extern volatile uint8_t i2c_address;
volatile uint8_t serial[4] = {0,0,0,0};
volatile uint16_t slope, offset;
volatile uint8_t cal_data[4];
volatile uint8_t read_type;
/**
 * 
 */
void init_I2C(uint8_t addr);


/**
 * 
 */
void I2C_ISR(void);


/**
 * 
 */
void i2c_write(uint8_t byte);


/**
 * 
 */
uint8_t i2c_read(void);


/**
 * 
 */
void i2c_wait(void);

#endif /*I2C_H*/
