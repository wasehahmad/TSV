#include "task_watchdog.h"
#include "params.h"

#include "atom.h"

void reset_watch_list(void){
	for(i=0;i<NUM_TASKS;i++){
		watch_dog_list[i]=0;
	}
}

void task_watchdog(uint32_t data) {
	DDRA |= (0x01);
	uint8_t i = 0;
	pet_dog = true;
	wait_counter = 0;

	//initialize to 0s
	reset_watch_list();
	atomTimerDelay(30);//wait before trying to check again

	for(;;) {

		for(i=0;i<NUM_TASKS;i++){
			if(watch_dog_list[i]==0){
				wait_counter++;
				break;
			}
		}
		if(i==NUM_TASKS){//if no break occurred
			reset_watch_list();
		}


		if(wait_counter == MAX_WAIT){
			pet_dog = false;
		}

		if(pet_dog){
			PORTA &= (0xFE);
			atomTimerDelay(3);
			PORTA |= (0x01);
			atomTimerDelay(3);
		}
	}
}
