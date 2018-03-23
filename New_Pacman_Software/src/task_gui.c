#include "task_gui.h"
#include "lcd.h"
#include "atom.h"
#include "atomport.h"
#include "params.h"
#include "i2c.h"
#include <avr/eeprom.h>

void task_gui_init(){
	display_top();
}

void task_gui(uint32_t data) {
  //uint8_t i = 0;
	task_gui_init();

  config_addr[5] = 0x06; // SCREEN RESET TIME
  config_addr[6] = 0x07; // SCREEN SLEEP TIME

  screen_reset_time = eeprom_read_byte((uint8_t*)EEPROM_SCREEN_RESET_TIME);
  
  if((screen_reset_time == 0) || (screen_reset_time == 0xFF)) {
  	eeprom_write_byte((uint8_t*)EEPROM_SCREEN_RESET_TIME, DEFAULT_SCREEN_RESET_TIME);
  	screen_reset_time = eeprom_read_byte((uint8_t*)EEPROM_SCREEN_RESET_TIME);
  }

  screen_sleep_time = eeprom_read_byte((uint8_t*)EEPROM_SCREEN_SLEEP_TIME);
  
  if((screen_sleep_time == 0) || (screen_sleep_time == 0xFF)) {
  	eeprom_write_byte((uint8_t*)EEPROM_SCREEN_SLEEP_TIME, DEFAULT_SCREEN_SLEEP_TIME);
  	screen_sleep_time = eeprom_read_byte((uint8_t*)EEPROM_SCREEN_SLEEP_TIME);
  }

  int8_t screen = 0;
  //int8_t cal = 1;

  uint8_t menu = 0;

  sleep_time = atomTimeGet();

  atomTimerDelay(100);

  for(;;){
  	watch_dog_list[WATCH_GUI]=1;//avoid overflow

    if(((atomTimeGet() - sleep_time)/100) > screen_reset_time){ // NO BUTTONS HAVE BEEN PRESSED FOR 30 SECONDS, GO BACK TO ORIGINAL MENU
    	if(pack_state==chrg){
    		menu=1;
    	}
    	menu = 0;
    	screen = 0;
    }
    if(((atomTimeGet() - sleep_time)/100) > screen_sleep_time){ // NO BUTTONS HAVE BEEN PRESSED FOR 2 MINUTES, TURN OFF DISPLAY
    	lcd_off();
	  // TODO remove lcd_active, lcd_off does it
    }else{
    	lcd_active = 1;
    	switch(menu){
    		case 0:
    		switch(screen){
    			case 0:
    			display_top(); break;
    			case 1:
    			disp_cell_info_screen(); break;
    			case 2:
    			disp_cell_cal_screen(); break;
    			case 3:
    			disp_logged_states_screen(); break;
    			case 15:
	  ////cal = set_can_address();
	  //cal = set_pack_num();
	  //set_num_cells();
	  //if (cal==0) screen = 0;  // exit config mode
    			set_config_param();
    			screen = 0;
    			break;
    			default:
    			display_top();
    		}
    		break;
    		case 1:
	//if((screen)<ams_board_count){
    		display_cell(screen);	
    		break;
	//}
    		case 2:
	//if((screen)<ams_board_count){
    		display_cell_cal(screen);	
    		break;
	//}
    		case 3:
	//if((screen)<5){
    		display_logged_states(screen);	
    		break;
	//}
    		default:
    		display_top();
      }//end switch screen
      //}
  }
    //ENTER BUTTON PRESSED:
  if((PINB & 0x01) == 0x00 && !prev_button_enter){
  	prev_button_enter=true;
  	sleep_time = atomTimeGet();
  	switch(menu){
  		case 0:
  		switch(screen){
  			case 0:
	  if(lcd_active) screen = 15;// enter config mode
	  break;
	  case 1:
	  if(lcd_active){
	  	menu = 1;
	  	screen = 0;
	  }
	  break;
	  case 2:
	  if(lcd_active){
	  	menu = 2;
	  	screen = 0;
	  }
	  break;
	  case 3:
	  if(lcd_active){
	  	menu = 3;
	  	screen = 0;
	  }
	  break;
	}
	break;
	case 1:
	if(lcd_active){
		screen = 1;
		menu = 0;
	}
	break;
	case 2:
	if(lcd_active){
		screen = 2;
		menu = 0;
	}
	break;
	case 3:
	if(lcd_active){
		screen = 3;
		menu = 0;
	}
	break;
	
}
}
else if(button_down){
	sleep_time = atomTimeGet();
	if(lcd_active) {
		screen = screen + 1;
	if((screen == 4) && (menu == 0)){ // max + 1
	  screen = 3;		// max
	}else if((screen == ams_board_count) && (menu == 2)){
		screen = ams_board_count - 1;
	}else if((screen == 2) && (menu ==1)){//two screens, one for temperatures one for voltages
		screen = 1;
	}else if ((screen == 5) && (menu == 3)){
		screen = 4;
	}
}
button_down = false;
}
else if(button_up){
	sleep_time = atomTimeGet();
	if(lcd_active) {
		screen = screen - 1;
		if(screen ==-1){
			screen = 0;
		}
	}
	button_up = false;
}
atomTimerDelay(20);
  }//end infinite for loop
}
