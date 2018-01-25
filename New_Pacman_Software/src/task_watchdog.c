#include "task_watchdog.h"
#include "params.h"

#include "atom.h"

void task_watchdog(uint32_t data) {
	DDRA |= (0x01);
	uint8_t i = 0;
	for(i=0;i<NUM_TASKS;i++){
		watch_dog_list[i]=0;
	}
	
	for(;;) {
		PORTA &= (0xFE);
		atomTimerDelay(3);
		PORTA |= (0x01);
		atomTimerDelay(3);
	}
}
