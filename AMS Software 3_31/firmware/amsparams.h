#ifndef AMSPARAMS_H
#define AMSPARAMS_H

// device input/outputs
#define MCLR    LATAbits.LATA5  // pin RA5
#define ACTLED  LATAbits.LATA6  // pin RA6
#define BYPASS  LATBbits.LATB0  // pin RB0
#define SDA1    LATBbits.LATB1  // pin RB1
#define SCL1    LATBbits.LATB4  // pin RB4
#define ICSPCLK LATBbits.LATB6  // pin RB6
#define ICSPDAT LATBbits.LATB7  // pin RB7

// command values
#define CLR_BY           0x00
#define SET_BY           0x01
#define PANIC            0x02
#define RELAX            0x03
#define SET_ADDR         0x04
#define SET_BYTIME       0x05
#define SET_V_CAL        0x06
#define SET_SERIAL       0x07
#define CHANGE_READ_TYPE 0x30

// i2c read types
#define READ_VOLTAGE  0x00
#define READ_SERIAL   0x01
#define READ_CAL_DATA 0x02
#define READ_MAGIC    0x03

// EEPROM parameters
#define DEFAULT_ADDR   (0x04 << 2)  // default I2C address
#define DEFAULT_BYTIME 0x00FF       // default bypass time
#define DEFAULT_V_CAL  0x00000000   // defauult cell voltage calibration
#define EEPROM_ADDR    1            // slave_id memory location
#define EEPROM_BYTIME  2            // location of the bypass limit (2 bytes)
#define EEPROM_V_CAL   4            // location of voltage calibration info (4 bytes)
#define EEPROM_SERIAL  8            // location of the serial number (4 bytes)

// adc multiplexer enumeration
#define ADC_WAIT    0
#define ADC_VOLT    1
#define ADC_TEMP    2

// adc channels of connected devices
#define ADC_CHAN_VOLT  10
#define ADC_CHAN_TEMP   9

// preprocessor pin numbers
#define PIN_0    0
#define PIN_1    1
#define PIN_2    2
#define PIN_3    3
#define PIN_4    4
#define PIN_5    5
#define PIN_6    6
#define PIN_7    7

#endif /*AMSPARAMS_H*/
