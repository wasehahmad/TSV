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

  uint8_t menu = 0;

  uint32_t sleep_time = atomTimeGet();

  atomTimerDelay(100);
	
  for(;;){
    if(((atomTimeGet() - sleep_time)/100) > 30){ // NO BUTTONS HAVE BEEN PRESSED FOR 30 SECONDS, GO BACK TO ORIGINAL MENU
      menu = 0;
      screen = 0;
    }
    if(((atomTimeGet() - sleep_time)/100) > 120){ // NO BUTTONS HAVE BEEN PRESSED FOR 2 MINUTES, TURN OFF DISPLAY
      lcd_off();
      lcd_active = 0;
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
	  cal = set_pack_num();
	  set_num_cells();
	  if (cal==0) screen = 0;  // exit config mode
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
    if((PINB & 0x01) == 0x00){
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
	}else if((screen == ams_board_count) && ((menu == 1) || (menu == 2))){
	  screen = ams_board_count - 1;
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
    //lcd_off(); // testing, be sure to remove!!!
    atomTimerDelay(50);
  }//end infinite for loop
}
