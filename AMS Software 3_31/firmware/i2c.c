#include "i2c.h"

// XC8 compiler PIC library
#include <xc.h>

// local includes
#include "amsparams.h"
#include "adc.h"
#include "watchdog.h"
#include "eeprom.h"

volatile bool bypass_flag;
volatile bool panic_flag;


volatile uint8_t i2c_address;// = DEFAULT_ADDR;

void init_I2C(uint8_t addr) {
        bypass_flag = 0;
        
        panic_flag = 0;

	// disable I2C interrupts
	PIE1bits.SSP1IE = 0;
	// enable SMBus specific inputs
	SSP1STATbits.CKE = 1;
	
	// enable the serial port pins
	SSP1CON1bits.SSPEN = 1;
	
	// release the clock to allow transmissions
	SSP1CON1bits.CKP = 1;
	
	// set to SSP modue to I2C slave mode with 7-bit address
	SSP1CON1bits.SSPM = 0b0110;

	// enable interrupts on a general call
	// the system will respond to (ID 0x00)
	SSP1CON2bits.GCEN = 1;
	
	// enable clock stretching
	SSP1CON2bits.SEN  = 1;

	// set the address mask to consider all address bits
	SSP1MSK = 0xFF;

	// pull the device I2C address from memory
	i2c_address = (addr << 1);
	
	// set the device I2C address
	SSP1ADD =  (addr << 1);
	
	// enable I2C interrupts
	PIE1bits.SSP1IE = 1;
}

void I2C_ISR(void) {
	// turn ACT led on while message is being processing
	ACTLED = 1;

	// do not respond if the clock line is not waiting for a response
	if(SSP1CON1bits.CKP != 0) return;
	
	// write operation
	if(SSP1STATbits.R_nW == 0) {
		//throw out slave address
		i2c_read();
		
		// read the command from the i2c line
		uint8_t cmd = i2c_read();
                
		
		switch(cmd) {
			
			case CLR_BY: {
				// disable bypass, set bypass pin to low
				bypass_flag = 0;

				break;
			}
			
			case SET_BY: {
				// enable bypass, set bypass pin to high
				bypass_flag = 1;
				
				// reset the bypass counter
				bypass_count = 0;
				
				break;
			}
			
			case PANIC: {
				// enable panic mode
				panic_flag = 1;
				
				break;
			}
			
			// RELAX command
			case RELAX: {
				// disable panic mode
				panic_flag = 0;
				
				break;
			}
			
			case SET_ADDR: {
				// read new address from i2c bus
				i2c_address = i2c_read();
				
				// write the new address to memory
				write_eeprom(EEPROM_ADDR, i2c_address);
				
				// update address register
				init_I2C(i2c_address);

				// reset processor
				RESET();
				
				break;
			}
			
			case SET_BYTIME: {
				// read bypass counter value from I2C
				uint8_t high_byte = i2c_read();
				uint8_t low_byte  = i2c_read();

				// update bypass counter value
				bypass_limit = (high_byte << 8) | low_byte;
				
				// save the upper and lower bytes of the limit
				write_eeprom(EEPROM_BYTIME, high_byte);
				write_eeprom(EEPROM_BYTIME + 1, low_byte);

				break;
			}
                        
                        case SET_V_CAL: {
                                // set the cell voltage calibration numbers from
                                // AMS Verification Unit
                                cal_data[3] = i2c_read();
                                cal_data[2] = i2c_read();
                                cal_data[1] = i2c_read();
                                cal_data[0] = i2c_read();

                                // Update slope and offset values
                                slope  = (cal_data[3] << 8) | cal_data[2];
                                offset = (cal_data[1] << 8) | cal_data[0];

                                // save the upper and lower bytes of the slope
                                // and offset
                                write_eeprom(EEPROM_V_CAL,     cal_data[3]);
				write_eeprom(EEPROM_V_CAL + 1, cal_data[2]);
                                write_eeprom(EEPROM_V_CAL + 2, cal_data[1]);
                                write_eeprom(EEPROM_V_CAL + 3, cal_data[0]);

                                break;
                        }
                        case SET_SERIAL: {
                                serial[3] = i2c_read();
                                serial[2] = i2c_read();
                                serial[1] = i2c_read();
                                serial[0] = i2c_read();

                                write_eeprom(EEPROM_SERIAL,     serial[3]);
                                write_eeprom(EEPROM_SERIAL + 1, serial[2]);
                                write_eeprom(EEPROM_SERIAL + 2, serial[1]);
                                write_eeprom(EEPROM_SERIAL + 3, serial[0]);

                                break;
                        }
                        case CHANGE_READ_TYPE: {
                                read_type = i2c_read();

                                break;
                        }
                        default: {
                        // do nothing
                        }
                    }
            }
            // read operation
            else {
                switch(read_type) {
                        case READ_VOLTAGE: {
                                // write the upper and lower voltage bytes
                                i2c_write(voltage >> 8);
                                i2c_write(voltage & 0xFF);

                                // write the upper and lower temp bytes
                                i2c_write(temp >> 8);
                                i2c_write(temp & 0xFF);
                                break;

                        }
                        case READ_SERIAL: {
                                // serial code data
                                serial[3] = read_eeprom(EEPROM_SERIAL);
                                serial[2] = read_eeprom(EEPROM_SERIAL + 1);
                                serial[1] = read_eeprom(EEPROM_SERIAL + 2);
                                serial[0] = read_eeprom(EEPROM_SERIAL + 3);

                                i2c_write(serial[3]);
                                i2c_write(serial[2]);
                                i2c_write(serial[1]);
                                i2c_write(serial[0]);
                                break;
                        }
                        case READ_CAL_DATA: {
                                // calibration data
                                cal_data[3] = read_eeprom(EEPROM_V_CAL);
                                cal_data[2] = read_eeprom(EEPROM_V_CAL + 1);
                                cal_data[1] = read_eeprom(EEPROM_V_CAL + 2);
                                cal_data[0] = read_eeprom(EEPROM_V_CAL + 3);


                                i2c_write(cal_data[3]);
                                i2c_write(cal_data[2]);
                                i2c_write(cal_data[1]);
                                i2c_write(cal_data[0]);
                                break;
                        }
                        case READ_MAGIC: {
                                // send the value 0xA5A5
                                i2c_write(0xA5);
                                i2c_write(0xA5);
                                break;
                        }
                        default: {
                        // do nothing
                        }
                }
                // set read value back to default temp/voltage
                read_type = READ_VOLTAGE;
	}

	// release the I2C clock
	SSP1CON1bits.CKP = 1;
	
	// clear the i2c interrupt flag
	PIR1bits.SSP1IF = 0;
	
	// done processing message, turn ACT led off
	ACTLED = 0;
}

void i2c_write(uint8_t byte) {
	// wait for the clock to be held again
	while(SSP1CON1bits.CKP) {}
	
	// send the byte to the i2c write register
	SSP1BUF = byte;
	
	// release the clock line to send the data
	SSP1CON1bits.CKP = 1;
}

uint8_t i2c_read(void) {
	// wait for another I2C message
	while(!PIR1bits.SSP1IF) ;
	// clear the i2c interrupt flag
	PIR1bits.SSP1IF = 0;

	// wait for data in I2C buffer, read 
	while(!SSP1STATbits.BF) ;
	uint8_t byte = SSP1BUF;
	
	// clear buffer full flag
	SSP1STATbits.BF = 0;

	// release i2c clock
	SSP1CON1bits.CKP = 1;
	
	// return the read i2c byte
	return byte;
}
