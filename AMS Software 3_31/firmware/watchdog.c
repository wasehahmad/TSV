#include "watchdog.h"

// XC8 compiler PIC library
#include <xc.h>

// local includes
#include "amsparams.h"
#include "watchdog.h"
#include "i2c.h"
#include "adc.h"
#include "eeprom.h"

// count the number of wdt cycles until bypass
volatile uint16_t bypass_count;

// the maximum number of wdt cycles until bypass occurs
volatile uint16_t bypass_limit;

// configures WATCHDOG to timeout every 256ms
// changed in Spring 2017 by Emilie Grybos
void init_WDT() {
	// configure watchdog timer interval ~256ms
	// WDTCON = ( 0b1000 << WDTPS);
	WDTCONbits.WDTPS0 = 0;
	WDTCONbits.WDTPS1 = 0;
	WDTCONbits.WDTPS2 = 1; //0
	WDTCONbits.WDTPS3 = 0; //1
	WDTCONbits.WDTPS4 = 0;
}

// WDT wakeup occured, handle event
void event_wdt(void) {
	//
	// BYPASS COUNTER
	// 
	// check if bypass limit has occured
	if(bypass_count == bypass_limit) {
		// clear bypass
		bypass_flag = 0;
	}
	// increment bypass_count
	else {
		bypass_count++;
	}
	
	//
	// ADC SAMPLING
	// 
	// start data collection, roll through all
	// connected/active adc channels
	adc_chan = ADC_VOLT;
	
	// set the ADC channel to the voltage input
	ADCON0bits.CHS = ADC_CHAN_VOLT; 
	
	// enable the ADC
	ADCON0bits.ADON = 1;
	
	// start an ADC conversion
	ADCON0bits.GO = 1;
}
