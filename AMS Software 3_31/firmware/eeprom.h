#ifndef EEPROM_H
#define EEPROM_H

// http://www.microchip.com/forums/m103053.aspx

#include <stdint.h>

/**
* @brief 
*
* @param address
*
* @return 
*/
uint8_t read_eeprom(uint8_t address);

/**
* @brief 
*
* @param address
* @param data
*
* @return 
*/
uint8_t write_eeprom(uint8_t address, uint8_t data);

#endif /*EEPROM_H*/
