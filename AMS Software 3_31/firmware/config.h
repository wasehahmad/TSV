#ifndef CONFIG_H
#define CONFIG_H

//
// PIC16 CONFIGURATION BITS
// 
#pragma config FOSC = INTOSC
#pragma config WDTE = ON
#pragma config PWRTE = OFF
#pragma config MCLRE = ON
#pragma config CP = OFF
#pragma config CPD = OFF
#pragma config BOREN = ON
#pragma config CLKOUTEN = OFF
#pragma config IESO = ON
#pragma config FCMEN = ON
#pragma config WRT = OFF
#pragma config PLLEN = OFF
#pragma config STVREN = ON
#pragma config BORV = LO
#pragma config LVP = ON

//
// EEPROM DEFAULT VALUES
// 
//__EEPROM_DATA(0x04, 0x00, 0x05);

#endif /*CONFIG_H*/
