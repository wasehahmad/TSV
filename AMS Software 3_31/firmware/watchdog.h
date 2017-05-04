#ifndef WATCHDOG_H
#define WATCHDOG_H

// C standard libraries
#include <stdbool.h>
#include <stdint.h>

extern volatile uint16_t bypass_count;

extern volatile uint16_t bypass_limit;

void init_WDT();  // initialize the timers

void event_wdt(void);
#endif /*WATCHDOG_H*/
