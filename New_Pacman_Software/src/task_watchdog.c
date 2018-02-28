#include "task_watchdog.h"
#include "params.h"

#include "atom.h"

void reset_watch_list(void){

	for(uint8_t i=0;i<NUM_TASKS;i++){
		watch_dog_list[i]=0;
	}
}

void task_watchdog(uint32_t data) {
	DDRA |= (0x01);
	
	pet_dog = true;
	wait_counter = 0;

	//initialize to 0s
	reset_watch_list();
	atomTimerDelay(30);//wait before trying to check again
	uint8_t i = 0;
	for(;;) {
		watch_dog_list[0]=1;//Yes
		// watch_dog_list[1]=1;//No
		// watch_dog_list[2]=1;//no
		// watch_dog_list[3]=1;//no
		// watch_dog_list[4]=1;//no
		// watch_dog_list[5]=1;//no
		// watch_dog_list[6]=1;//no
		// watch_dog_list[7]=1;//no


		for(i=0;i<NUM_TASKS;i++){
			if(watch_dog_list[i]==0){
				wait_counter++;
				break;
			}
		}
		if(i==NUM_TASKS){//if no break occurred in for loop
			reset_watch_list();
			wait_counter = 0;
		}


		if(wait_counter >= MAX_WAIT){
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
