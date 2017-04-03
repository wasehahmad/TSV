#include "task_gui.h"
#include "lcd.h"
#include "atom.h"
#include "atomport.h"
#include "params.h"
#include "i2c.h"

void task_gui_init(){
	display_top();
}

void task_gui(uint32_t data) {
	//uint8_t i = 0;
	task_gui_init();
	int8_t screen = 0;
	int8_t cal = 1;
	atomTimerDelay(100);
	
	for(;;){
		switch(screen){
			case 0:
				display_top(); break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
				if((screen-1)<ams_board_count){
					display_cell(screen-1);	
					break;
				}break;
			case 8:  
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
				if((screen-8)<ams_board_count){
					display_cell_cal(screen-8);	
					break;
				}break;
			case 15:
			  cal = set_can_address();
			  cal = set_pack_num();
				if (cal==0) screen = 0;  // exit config mode
				break;
			default:
				display_top();
		}			
			
			if( (PINB & 0x01) == 0x00){ // enter config mode
				screen = 15;
			}
			else if(button_down){
				screen = screen + 1;
				if(screen ==15){				// max + 1
					screen = 14;				// max
				}
				button_down = false;
			}
			else if(button_up){
				screen = screen - 1;
				if(screen ==-1){
					screen = 0;
				}
				button_up = false;
			}	
	}
}
