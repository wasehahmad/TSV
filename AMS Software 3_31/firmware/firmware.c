/******************************************************************************
 *  Filename:       firmware.c
 *  Date:           09/29/15
 *  File Verison:   3.0
 *
 *  Authors:        Alex Hytha     (LFEV'15 4/03/15)
 *                  John Gehrig    (LFEV'15 09/29/15)
 *                  
 *  Team:           LFEV'15
 *
 * ****************************************************************************
 *  Architecture:   Enhanced Midrange PIC
 *  Processor:      PIC16LF1827
 *  Compiler:       MPLAB X XC8
 *
 * ****************************************************************************
 *  Description:    Firmware for the slave pic
 *
 * ****************************************************************************
 *  Pin Assignments: FIXME
 *      LEDS:
 *          RA6 -- PLED
 *          RA7 -- WDT LED (not implemented on the BMS board)
 *          RB0 -- Bypass LED
 *
 *      ANALOG INPUT CHANNELS:
 *          RB2/AN10 --  Temp
 *          RB3/AN9  --  Volt
 *
 *****************************************************************************/

#include "config.h"
#include "amsparams.h"

#include <xc.h>
#include <stdint.h>

#include "adc.h"
#include "i2c.h"
#include "watchdog.h"
#include "eeprom.h"

/**
 * 
 */
void setup() {
	// clear ports A and B
	LATA = 0x00;
	LATB = 0x00;
	
	// set the pin input/output directions
	TRISA  = (1 << PIN_5);
	TRISB  = (1 << PIN_1) |
			 (1 << PIN_2) |
			 (1 << PIN_3) |
			 (1 << PIN_4);


	// set up the ADC ports
	ANSELB = (1 << PIN_2) |
			 (1 << PIN_3);
	//
	// CHECK EEPROM
	//
	i2c_address = read_eeprom(EEPROM_ADDR);

	if((i2c_address == 0x00) || (i2c_address == 0xFF)) {
		write_eeprom(EEPROM_ADDR, DEFAULT_ADDR);
		i2c_address = read_eeprom(EEPROM_ADDR);
	}

	// load the bypass limit from memory
	bypass_limit =
			(read_eeprom(EEPROM_BYTIME) << 8) |
			(read_eeprom(EEPROM_BYTIME + 1));
	if((bypass_limit == 0x00) || (bypass_limit == 0xFF)) {
		write_eeprom(EEPROM_ADDR, DEFAULT_BYTIME);
		bypass_limit =
				(read_eeprom(EEPROM_BYTIME) << 8) |
				(read_eeprom(EEPROM_BYTIME + 1));
	}

	        // serial code data
                serial[3] = read_eeprom(EEPROM_SERIAL);
                serial[2] = read_eeprom(EEPROM_SERIAL + 1);
                serial[1] = read_eeprom(EEPROM_SERIAL + 2);
                serial[0] = read_eeprom(EEPROM_SERIAL + 3);

                // calibration data
                cal_data[3] = read_eeprom(EEPROM_V_CAL);
                cal_data[2] = read_eeprom(EEPROM_V_CAL + 1);
                cal_data[1] = read_eeprom(EEPROM_V_CAL + 2);
                cal_data[0] = read_eeprom(EEPROM_V_CAL + 3);
                // Update slope and offset values
                slope  = (cal_data[3] << 8) | cal_data[2];
                offset = (cal_data[1] << 8) | cal_data[0];

                // set read type to default (voltage/temp)
                read_type = READ_VOLTAGE;
                
	// initialize the watchdog timer
	init_WDT();
	
	// initialize the I2C bus
	init_I2C(i2c_address);
	
	// initialize the ADC
	init_ADC();
}

/**
 * 
 */
void interrupt ISR(void) {
	// disable global and peripheral interrupts
	INTCONbits.GIE  = 0;
	INTCONbits.PEIE = 0;

	// handle the I2C interrupt 
	if( PIR1bits.SSP1IF ) I2C_ISR();

	// handle the ADC interrupt 
	if( PIR1bits.ADIF ) ADC_ISR();
	
	// enable global and peripheral interrupts
	INTCONbits.GIE = 1;
	INTCONbits.PEIE = 1;
}

/**
 * 
 */
int main(void){
	// the following is disabled because a 1MHz system clock uses less power
	// delays 10 cycles, then switches to internal 8 MHz Clock
	//_delay(10);
	//OSCCON = 0x72;

	// initialize the slave PIC, enable interrupts
	setup();   
	
	// enable global and peripheral interrupts
	INTCONbits.PEIE = 1;
	INTCONbits.GIE  = 1;

	// act led state for PANIC command
	bool panic_led = 0;

	// save power while waiting for interrupts
	while(1) {
		// place PIC in sleep mode
		SLEEP();

		// WDT wakeup occured, handle
		event_wdt();

		// bug, gpio set in the isr does not stay set
		// ternary operator must be used, simply setting bypass
		// to bypass flag also causes this same error(cleared value)
		// panic flag behaves in the same way, setting ACTLED to 
		// the below expression (panic_led) does not work.
		// The intermediary panic_led variable must be used.
		//
		// seems like an optimizer error to me, volatile is being used
		//
		// XC8 v1.35 & v1.12 tested (both same problem)
		// Engineer: John Gehrig
		panic_led = (panic_flag) ? ~panic_led : 0;
		BYPASS = bypass_flag;
		ACTLED = (panic_flag) ? panic_led : 0;
	}
	
	return 0;
}

