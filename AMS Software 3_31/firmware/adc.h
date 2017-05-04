#ifndef ADC_H
#define ADC_H

// C standard libraries
#include <stdint.h>

/**
 * 
 */
extern uint16_t voltage;


/**
 * 
 */
extern uint16_t temp;



/**
 * 
 */
extern uint8_t  adc_chan;


/**
 * 
 */
void ADC_ISR(void);

/**
 * 
 */
void init_ADC(void);
#endif /*ADC_H*/
