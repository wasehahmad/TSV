#ifndef TASK_WATCHDOG_H
#define TASK_WATCHDOG_H

#include <stdint.h>

#define MAX_WAIT 10

void task_watchdog(uint32_t data);
void reset_watch_list(void);

volatile bool pet_dog;
volatile uint8_t wait_counter;

#endif /*TASK_WATCHDOG*/
