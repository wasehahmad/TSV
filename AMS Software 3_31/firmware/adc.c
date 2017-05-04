#include "adc.h"


// XC8 compiler PIC library
#include <xc.h>

// C standard int types
#include <stdint.h>

// local includes
#include "amsparams.h"

// cell voltage adc result
uint16_t voltage;

// cell temperature adc result
uint16_t temp;

// the current stage of data collection (for the adc)
uint8_t adc_chan;

void init_ADC() {
	// generate the fixed voltage reference
	// enable fixed reference voltage
	FVRCONbits.FVREN = 1; 
	
	// set the fixed voltage to 2.048
	FVRCONbits.ADFVR = 0b10;

	// set the voltage references
	// VDD / VSS : VFR / GND
	ADCON1bits.ADPREF = 0b11;
	ADCON1bits.ADNREF = 0b00;

	// set ADC clock to dedicated FRC clock
	// this is required to use ADC in sleep mode
	ADCON1bits.ADCS = 0b011;
	
	// set the ADC output to be right-justified
	ADCON1bits.ADFM = 1;
	
	// enable ADC interrupts
	PIE1bits.ADIE = 1;
}

void ADC_ISR(void) {
	switch(adc_chan) {
		// sample 1 -- pack voltage
		case ADC_VOLT:
			// update the global voltage variable from the ADC result
			voltage = (ADRESH << 8) | (ADRESL);
			
			// set up for reading ADC_TEMP
			adc_chan = ADC_TEMP;
			ADCON0bits.CHS  = ADC_CHAN_TEMP;
			
			// start a new conversion
			ADCON0bits.GO   = 1;
			break;
		
		// sample 2 -- pack temperature
		case ADC_TEMP:

			// update the global temperature variable from the ADC result
			temp = (ADRESH << 8) | ADRESL;
			
			adc_chan = ADC_WAIT;
			
			// turn off the ADC to conserve power
			ADCON0bits.ADON = 0;
			
			break;

	}
	
	// clear the ADC interrupt flag
	PIR1bits.ADIF = 0;
	
}




