#ifndef TASK_WATCHDOG_H
#define TASK_WATCHDOG_H

#include <stdint.h>

#define MAX_WAIT 200 //this allows enough time for the reset to occur without tripping the safety loop

void task_watchdog(uint32_t data);
void reset_watch_list(void);



#endif /*TASK_WATCHDOG*/
