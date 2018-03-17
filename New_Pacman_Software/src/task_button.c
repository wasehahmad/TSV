#include "task_button.h"


void task_button_init(void){
	DDRB &= ~(0x07);
	PORTB |= 0x07;
	button_enter=false;
	button_down=false;
	button_up=false;
	prev_button_up=false;
	prev_button_down=false;
	prev_button_enter=false;
}

void task_button(uint32_t data){
	
	task_button_init();
	// for(;;){
	// 	if((PINB & 0x04) != 0x04){// button 0 is depressed (up)
	// 		button_up = true;
	// 		while((PINB & 0x04) != 0x04){//wait for button to not be depressed
	// 			if((PINB & 0x02) != 0x02){button_enter = true;} //if button 1 is also being pressed
	// 			atomTimerDelay(5);
	// 		}
	// 		//while((PINB & 0x01) == 0x01){// wait 50 ms for switch bounce
	// 			atomTimerDelay(5);
	// 		//}
		
	// 	}else if((PINB & 0x02) != 0x02){// button 1 is depressed (down)
	// 		button_down = true;
	// 		while((PINB & 0x02) != 0x02){//wait for button to not be depressed
	// 			if((PINB & 0x04) != 0x04){button_enter = true;} //if button 0 is also being pressed
	// 			atomTimerDelay(5);
	// 		}
	// 		//while((PINB & 0x02) == 0x02){// wait 50 ms for switch bounce
	// 			atomTimerDelay(5);
	// 		//}

	// 	}else if((PINB & 0x01) != 0x01){// button 2 is depressed (select)
	// 		// button_enter = true;
	// 		// while((PINB & 0x01) != 0x01){//wait for button to not be depressed
	// 		// 	atomTimerDelay(5);	
	// 		// }
	// 	}
		
	// }
	
	atomTimerDelay(50);
	for(;;){
		watch_dog_list[WATCH_BUTTON]=1;//avoid overflow

		if((PINB & 0x04) != 0x04 && !prev_button_up){// button 0 is depressed (up)
			prev_button_up=true;
			button_up = true;
			atomTimerDelay(30);

		}else if((PINB & 0x02) != 0x02 && !prev_button_down){// button 1 is depressed (down)
			prev_button_down=true;
			button_down = true;
			atomTimerDelay(30);

		}
		/*else if((PINB & 0x01) != 0x01 && !prev_button_enter){// button 2 is depressed (select)
			prev_button_enter=true;
			button_enter = true;
			atomTimerDelay(30);	
		}*/
		//check if button has been used in lcd (!button_*) and the mechanical button has been released
		if((PINB & 0x01) == 0x01 ) {
			prev_button_enter=false;
		}
		if((PINB & 0x04) == 0x04 && !button_up) {
			prev_button_up=false;
		}
		if((PINB & 0x02) == 0x02 && !button_down) {
			prev_button_down=false;
		}

	
	}
}
