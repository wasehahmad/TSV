#include <stdint.h>

#include <xc.h>

// http://www.microchip.com/forums/m103053.aspx

uint8_t read_eeprom(uint8_t address) {
	// load address of EEPROM to read
	EEADR = address;
	
	// access EEPROM data memory
	EECON1bits.EEPGD = 0;
	
	// do not access configuration registers
	EECON1bits.CFGS = 0;
	
	// initiate read
	EECON1bits.RD = 1;
	
	// return EEPROM byte
	return EEDATA;
}

// Write Byte to internal EEPROM
uint8_t write_eeprom(uint8_t address, uint8_t data) {
	EECON1bits.WREN=1; // allow EEPROM writes
	EEADR=address; // load address of write to EEPROM
	EEDATA=data; // load data to write to EEPROM
	EECON1bits.EEPGD=0;// access EEPROM data memory
	EECON1bits.CFGS=0; // do not access configuration registers
	INTCONbits.GIE=0; // disable interrupts for critical EEPROM write sequence
	//===============//
	EECON2=0x55;
	EECON2=0xAA;
	EECON1bits.WR=1;
	//==============//
	INTCONbits.GIE=1; // enable interrupts, critical sequence complete
	while (EECON1bits.WR==1); // wait for write to complete
		
	EECON1bits.WREN=0; // do not allow EEPROM writes


	//Verify write operation
	if (read_eeprom(address)==data) // read the byte we just wrote to EEPROM
			return 1; // write was successful
	return 0; // write failed
}
