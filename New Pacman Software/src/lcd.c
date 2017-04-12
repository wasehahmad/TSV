#include "lcd.h"
#include "i2c.h"
#include <string.h>
#include "params.h"
#include "atomtimer.h"
#include <avr/eeprom.h>
#include "atomport.h"

#include <stdio.h>
//#include <math.h>



void write_lcd(void){
	lcd_transmit(0x80,0,0);
	lcd_reset();
	lcd_message((unsigned char*)&display_0, 20);
	lcd_message((unsigned char*)&display_1, 20);
	lcd_message((unsigned char*)&display_2, 20);
	lcd_message((unsigned char*)&display_3, 20);
}

void display_top(void){
	unsigned char line0[20] = {'S','T','A','T','E',':',' ',' ',' ',' ',' ',' ','S','O','C',':',' ',' ',' ','%'};
	unsigned char line1[20] = {'V',':',' ',' ',' ',' ',' ','A',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	unsigned char line2[20] = {'S','A','F','E','T','Y',' ','L','O','O','P',':',' ',' ',' ',' ',' ',' ',' ',' '};
	unsigned char line3[20] = {'M','>',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	char* d = "DEAD";
	switch(pack_state){
	case chrg: d = "CHRG";
		break;
	case chrgd: d = "CHRGD";
		break;
	case lco: d = "LCO";
		break;
	case flt: d = "FLT"; line0[10] = flt_cnd.cond+48;//line0[10] = fault_code+48; TESTING, REVERT BACK 03292017
		break;
	case dead: d = "DEAD";
		break;
	case rdy: d = "RDY";
		break;
	case boot: d = "BOOT";
		break;
	}
		
	memcpy(line0+6,d, strlen(d));
	
	line3[2] = 'v';
	line3[3] = (int8_t)version+48;
	line3[4] = '.';
	line3[5] = (int8_t)(version*10)%10+48;
	line3[6] = (int8_t)(version*100)%10+48;
	
	
	line0[16] = (pack_SOC/100)+48;
	line0[17] = ((pack_SOC%100)/10)+48;
	line0[18] = (pack_SOC%10)+48;
	
	line1[2] = (int)(pack_voltage)/100 +48;
	line1[3] = ((int)(pack_voltage/10) % 10)+48;
	line1[4] = '.';
	line1[5] = ((int)(pack_voltage) % 10)+48;
	
	int32_t disp_current = pack_current;
	if(pack_current<0.0){
		line1[9] = '-';
		disp_current = disp_current *-1.0;
	}
	line1[10] = (disp_current/100000)%10 + 48;
	line1[11] = (disp_current/10000)%10 + 48;
	line1[12] = (disp_current/1000)%10 +48;
	line1[13] = '.';
	line1[14] = (disp_current/100)%10 +48;
	line1[15] = (disp_current/10)%10 +48;
	line1[16] = disp_current%10 +48;
	
	if(sloop_state == true){
		line2[13] = 'C';
		line2[14] = 'L';
		line2[15] = 'O';
		line2[16] = 'S';
		line2[17] = 'E';
		line2[18] = 'D';
	}
	else{
		line2[13] = 'O';
		line2[14] = 'P';
		line2[15] = 'E';
		line2[16] = 'N';
		line2[17] = ' ';
		line2[18] = ' ';
	}
	
	uint32_t seconds = (atomTimeGet()/100); //100 system ticks per sec
	uint32_t minutes = (seconds/60);
	uint32_t hours = minutes/60;
	uint32_t days = hours/24;
	seconds = seconds%60;
	minutes = minutes%60;
	hours = hours%24;
	line3[19]= seconds%10+48;
	line3[18]= (seconds/10)%10+48;
	line3[17]= ':';
	line3[16]= (minutes)%10+48;
	line3[15]= (minutes/10)%10+48;
	line3[14]= ':';
	line3[13]= (hours)%10+48;
	line3[12]= (hours/10)%10+48;
	line3[11]= ':';
	line3[10]= (days)%10+48;
	line3[9]=  (days/10)%10+48;
	line3[8]=  (days/100)%10+48;
	
	memcpy((void*)display_0, (void*) line0, 20);
	memcpy((void*)display_1, (void*) line1, 20);
	memcpy((void*)display_2, (void*) line2, 20);
	memcpy((void*)display_3, (void*) line3, 20);
	}

// void display_chst(void){
// 	unsigned char line0[20] = {'L','A','S','T',' ','D','I','S','C','H','R','G','%',':',' ',' ',' ',' ',' ',' '};
// 	unsigned char line1[20] = {'L','A','S','T',' ','C','H','R','G','%',':',' ',' ',' ',' ',' ',' ',' ',' ',' '};
// 	unsigned char line2[20] = {'C','U','R','R','E','N','T',' ','C','H','R','G','%',':',' ',' ',' ',' ',' ',' '};
// 	unsigned char line3[20] = {'P','/','C','H','S','T','>',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
// 	memcpy((void*)display_0, (void*) line0, 20);
// 	memcpy((void*)display_1, (void*) line1, 20);
// 	memcpy((void*)display_2, (void*) line2, 20);
// 	memcpy((void*)display_3, (void*) line3, 20);
// }

void display_cal1(void){
	unsigned char line0[20] = {'V','O','F','F',':',' ',' ',' ',' ',' ','A','O','F','F',':',' ',' ',' ',' ',' '};
	unsigned char line1[20] = {'V','S','L','P',':',' ',' ',' ',' ',' ','A','S','L','P',':',' ',' ',' ',' ',' '};
	unsigned char line2[20] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	unsigned char line3[20] = {'P','/','C','A','L','>',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	if(pack_Voff <0.0){
		line0[5] = '-';
	}
	line0[6] = pack_Voff/1+48;
	line0[7] = '.';
	line0[8] = (int16_t)(pack_Voff*10)%10+48;
	
//	lin0[15] = 
	memcpy((void*)display_0, (void*) line0, 20);
	memcpy((void*)display_1, (void*) line1, 20);
	memcpy((void*)display_2, (void*) line2, 20);
	memcpy((void*)display_3, (void*) line3, 20);
}

// void display_cal1_voff(void){
// 	unsigned char line0[20] = {'V','O','F','F',':',' ',' ',' ',' ',' ','C','U','R','R','E','N','T',' ',' ',' '};
// 	unsigned char line1[20] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N','E','W',' ',' ',' ',' ',' ',' ',' '};
// 	unsigned char line2[20] = {'S','E','L','E','C','T',' ','D','I','G','I','T',' ','O','R',' ','O','K',' ',' '};
// 	unsigned char line3[20] = {'P','/','C','A','L','1','/','V','O','F','F','>',' ',' ',' ',' ',' ',' ',' ',' '};
// 	memcpy((void*)display_0, (void*) line0, 20);
// 	memcpy((void*)display_1, (void*) line1, 20);
// 	memcpy((void*)display_2, (void*) line2, 20);
// 	memcpy((void*)display_3, (void*) line3, 20);
// }

// void display_cal1_vslp(void){
// 	unsigned char line0[20] = {'V','S','L','P',':',' ',' ',' ',' ',' ','C','U','R','R','E','N','T',' ',' ',' '};
// 	unsigned char line1[20] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N','E','W',' ',' ',' ',' ',' ',' ',' '};
// 	unsigned char line2[20] = {'S','E','L','E','C','T',' ','D','I','G','I','T',' ','O','R',' ','O','K',' ',' '};
// 	unsigned char line3[20] = {'P','/','C','A','L','1','/','V','S','L','P','>',' ',' ',' ',' ',' ',' ',' ',' '};
// 	memcpy((void*)display_0, (void*) line0, 20);
// 	memcpy((void*)display_1, (void*) line1, 20);
// 	memcpy((void*)display_2, (void*) line2, 20);
// 	memcpy((void*)display_3, (void*) line3, 20);
// }

// void display_cal1_aoff(void){
// 	unsigned char line0[20] = {'A','O','F','F',':',' ',' ',' ',' ',' ','C','U','R','R','E','N','T',' ',' ',' '};
// 	unsigned char line1[20] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N','E','W',' ',' ',' ',' ',' ',' ',' '};
// 	unsigned char line2[20] = {'S','E','L','E','C','T',' ','D','I','G','I','T',' ','O','R',' ','O','K',' ',' '};
// 	unsigned char line3[20] = {'P','/','C','A','L','1','/','A','O','F','F','>',' ',' ',' ',' ',' ',' ',' ',' '};
// 	memcpy((void*)display_0, (void*) line0, 20);
// 	memcpy((void*)display_1, (void*) line1, 20);
// 	memcpy((void*)display_2, (void*) line2, 20);
// 	memcpy((void*)display_3, (void*) line3, 20);
// }

// void display_cal1_aslp(void){
// 	unsigned char line0[20] = {'A','S','L','P',':',' ',' ',' ',' ',' ','C','U','R','R','E','N','T',' ',' ',' '};
// 	unsigned char line1[20] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N','E','W',' ',' ',' ',' ',' ',' ',' '};
// 	unsigned char line2[20] = {'S','E','L','E','C','T',' ','D','I','G','I','T',' ','O','R',' ','O','K',' ',' '};
// 	unsigned char line3[20] = {'P','/','C','A','L','1','/','A','S','L','P','>',' ',' ',' ',' ',' ',' ',' ',' '};
// 	memcpy((void*)display_0, (void*) line0, 20);
// 	memcpy((void*)display_1, (void*) line1, 20);
// 	memcpy((void*)display_2, (void*) line2, 20);
// 	memcpy((void*)display_3, (void*) line3, 20);
// }

// void display_cal2(void){
// 	unsigned char line0[20] = {'T','H','I','S',' ','S','C','R','E','E','N',' ','W','I','L','L',' ',' ',' ',' '};
// 	unsigned char line1[20] = {'A','L','L','O','W',' ','C','E','L','L',' ','M','O','D','E','L',' ',' ',' ',' '};
// 	unsigned char line2[20] = {'P','A','R','A','M',' ','F','O','R',' ','S','O','C',' ',' ',' ',' ',' ',' ',' '};
// 	unsigned char line3[20] = {'P','/','C','A','L','2','>',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
// 	memcpy((void*)display_0, (void*) line0, 20);
// 	memcpy((void*)display_1, (void*) line1, 20);
// 	memcpy((void*)display_2, (void*) line2, 20);
// 	memcpy((void*)display_3, (void*) line3, 20);
// }
 
void display_cell(uint8_t cell){
	unsigned char line0[20] = {'S','T','A','T','E',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	unsigned char line1[20] = {'C',cell+48,'_','V',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	unsigned char line2[20] = {'C',cell+48,'_','T',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	unsigned char line3[20] = {'P','/','C',cell+48,'>',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};

	line1[5] = cell_V[cell]/1000 + 48;
	line1[6] = '.';
	line1[7] = (cell_V[cell]%1000)/100 + 48;
	line1[8] = (cell_V[cell]%1000)%100/10 +48;
	line1[9] = cell_V[cell] %10 + 48;
	

	line2[5] = cell_T[cell]/1000 + 48;
	line2[6] = (cell_T[cell]%1000)/100 + 48;
	line2[7] = (cell_T[cell]%1000)%100/10 +48;
	line2[8] = '.';
	line2[9] = cell_T[cell]%10 +48;

	memcpy((void*)display_0, (void*) line0, 20);
	memcpy((void*)display_1, (void*) line1, 20);
	memcpy((void*)display_2, (void*) line2, 20);
	memcpy((void*)display_3, (void*) line3, 20);
}

void display_cell_cal(uint8_t cell){
	unsigned char line0[20] = {'V','O','F','F',':',' ',' ',' ',' ',' ','T','O','F','F',':',' ',' ',' ',' ',' '};
	unsigned char line1[20] = {'V','S','L','P',':',' ',' ',' ',' ',' ','T','S','L','P',':',' ',' ',' ',' ',' '};
	unsigned char line2[20] = {'S','E','R','L',':',' ',' ',' ',' ',' ','A','D','D','R',':','0','x',' ',' ',' '};
	unsigned char line3[20] = {'P','/','C',cell+48,'/','C','A','L','>',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	
	// Clears the arrays
	for(int8_t i = 0; i<5;i++){
		slp_result[i] = ' ';
		off_result[i] = ' ';
	}
	
	// int to ascii method 
	// changes cell slp/off to ascii char arrays
	// might want to use the modulus division technique to display ints as used in above methods to save memory 
	itoa(cell_Vslp[cell], slp_result, 10);
	itoa(cell_Voff[cell], off_result, 10);

	// removes end of line char from array
	for(int8_t i = 0; i<5;i++){
		if(slp_result[i] == '\0') slp_result[i] = ' ';
		if(off_result[i] == '\0') off_result[i] = ' ';
	}
	
	//Vslp
	line1[5]  = slp_result[0];
	line1[6]  = slp_result[1];
	line1[7]  = slp_result[2];
	line1[8]  = slp_result[3];
	line1[9]  = slp_result[4];

	//Voff
	line0[5]  = off_result[0];
	line0[6]  = off_result[1];
	line0[7]  = off_result[2];
	line0[8]  = off_result[3];
	line0[9]  = off_result[4];

	//Toff
	line0[15] = ((cell_Toff[cell]%100)/10)+48;
	line0[16] = (cell_Toff[cell]%10)+48;
	
	// Tslp
	line1[15] = (int8_t)cell_Tslp[cell]+48;
	line1[16] = '.';
	line1[17] = (int8_t)(cell_Tslp[cell]*10)%10+48;
	line1[18] = (int8_t)(cell_Tslp[cell]*100)%10+48;
	if( (((int8_t)(cell_Tslp[cell]*1000)%10+48) > 47) && (((int8_t)(cell_Tslp[cell]*1000)%10+48) < 58)){ //Only dislays a 1000ths digit if there is one
		line1[19] = (int8_t)(cell_Tslp[cell]*1000)%10+48;
	}else line1[19] = ' ';

	//i2c address
	sprintf(&address[0], "%03X", ams_board_addr[cell]);
	line2[17] = address[0];
	line2[18] = address[1];
	line2[19] = address[2];


	// AMS Serial
	line2[5] = (ams_serial_array[cell][0])+48;
	line2[6] = (ams_serial_array[cell][1])+48;
	line2[7] = (ams_serial_array[cell][2])+48;
	line2[8] = (ams_serial_array[cell][3])+48;

	memcpy((void*)display_0, (void*) line0, 20);
	memcpy((void*)display_1, (void*) line1, 20);
	memcpy((void*)display_2, (void*) line2, 20);
	memcpy((void*)display_3, (void*) line3, 20);
}

// void display_cell_cal_voff(uint8_t cell){
// 	unsigned char line0[20] = {'V','O','F','F',':',' ',' ',' ',' ',' ','C','U','R','R','E','N','T',' ',' ',' '};
// 	unsigned char line1[20] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N','E','W',' ',' ',' ',' ',' ',' ',' '};
// 	unsigned char line2[20] = {'S','E','L','E','C','T',' ','D','I','G','I','T',' ','O','R',' ','O','K',' ',' '};
// 	unsigned char line3[20] = {'P','/','C',cell+48,'/','C','A','L','/','V','O','F','F','>',' ',' ',' ',' ',' ',' '};
// 	memcpy((void*)display_0, (void*) line0, 20);
// 	memcpy((void*)display_1, (void*) line1, 20);
// 	memcpy((void*)display_2, (void*) line2, 20);
// 	memcpy((void*)display_3, (void*) line3, 20);
// }

// void display_cell_cal_vslp(uint8_t cell){
// 	unsigned char line0[20] = {'V','S','L','P',':',' ',' ',' ',' ',' ','C','U','R','R','E','N','T',' ',' ',' '};
// 	unsigned char line1[20] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N','E','W',' ',' ',' ',' ',' ',' ',' '};
// 	unsigned char line2[20] = {'S','E','L','E','C','T',' ','D','I','G','I','T',' ','O','R',' ','O','K',' ',' '};
// 	unsigned char line3[20] = {'P','/','C',cell+48,'/','C','A','L','/','V','S','L','P','>',' ',' ',' ',' ',' ',' '};
// 	memcpy((void*)display_0, (void*) line0, 20);
// 	memcpy((void*)display_1, (void*) line1, 20);
// 	memcpy((void*)display_2, (void*) line2, 20);
// 	memcpy((void*)display_3, (void*) line3, 20);
// }

// void display_cell_cal_toff(uint8_t cell){
// 	unsigned char line0[20] = {'T','O','F','F',':',' ',' ',' ',' ',' ','C','U','R','R','E','N','T',' ',' ',' '};
// 	unsigned char line1[20] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N','E','W',' ',' ',' ',' ',' ',' ',' '};
// 	unsigned char line2[20] = {'S','E','L','E','C','T',' ','D','I','G','I','T',' ','O','R',' ','O','K',' ',' '};
// 	unsigned char line3[20] = {'P','/','C',cell+48,'/','C','A','L','/','T','O','F','F','>',' ',' ',' ',' ',' ',' '};
// 	memcpy((void*)display_0, (void*) line0, 20);
// 	memcpy((void*)display_1, (void*) line1, 20);
// 	memcpy((void*)display_2, (void*) line2, 20);
// 	memcpy((void*)display_3, (void*) line3, 20);
// }

// void display_cell_cal_tslp(uint8_t cell){
// 	unsigned char line0[20] = {'T','S','L','P',':',' ',' ',' ',' ',' ','C','U','R','R','E','N','T',' ',' ',' '};
// 	unsigned char line1[20] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N','E','W',' ',' ',' ',' ',' ',' ',' '};
// 	unsigned char line2[20] = {'S','E','L','E','C','T',' ','D','I','G','I','T',' ','O','R',' ','O','K',' ',' '};
// 	unsigned char line3[20] = {'P','/','C',cell+48,'/','C','A','L','/','T','S','L','P','>',' ',' ',' ',' ',' ',' '};
// 	memcpy((void*)display_0, (void*) line0, 20);
// 	memcpy((void*)display_1, (void*) line1, 20);
// 	memcpy((void*)display_2, (void*) line2, 20);
// 	memcpy((void*)display_3, (void*) line3, 20);
// }


int8_t set_pack_num(){

  //atomTimerDelay(700);

  unsigned char line_0[20] = {'S','E','T',' ','P','A','C','K',' ','I','D',' ',' ',' ',' ',' ',' ',' ',' ',' '};
  unsigned char line_1[20] = {'U','P','/','D','O','W','N',' ','T','O',' ','C','H','A','N','G','E',' ',' ',' '};
  unsigned char line_2[20] = {'E','N','T','E','R',' ','T','O',' ','S','E','T',' ',' ',' ',' ',' ',' ',' ',' '};
  unsigned char line_3[20] = {'C','U','R','R','>',' ',' ',' ',' ',' ',' ','N','X','T','>',' ',' ',' ',' ',' '};

  memcpy((void*)display_0, (void*) line_0, 20);
  memcpy((void*)display_1, (void*) line_1, 20);
  memcpy((void*)display_2, (void*) line_2, 20);
  memcpy((void*)display_3, (void*) line_3, 20);

  atomTimerDelay(100);
	
  pack_num_choice = PACK_NUM;
  sprintf(&curr_pack_id[0], "%02X", PACK_NUM);
  sprintf(&next_pack_id[0], "%02X", pack_num_choice);

  atomTimerDelay(50);
	
  sel = 1;
  // choice for pack id: 1 - 0x7f = 1 - 127
  for(;;){
		
    if(button_up){
      //if(sel < 4){
	sel++;
	//}
      pack_num_choice = sel;
      
      if(pack_num_choice == 128){
	sel = 1;
	pack_num_choice = sel;
      }
      sprintf(&next_pack_id[0], "%02X", pack_num_choice);
      button_up = false;
		
    }else if(button_down){
      sel--;
      if(sel == 0){
	sel = 127;
      }
      pack_num_choice = sel;
      sprintf(&next_pack_id[0], "%02X", pack_num_choice);
      button_down = false;
    }
		
    //displays var sel
    //should change when down is pressed
    //line1[17] = sel+48;

    //current pack CAN address  //asdf
    line_3[7] = curr_pack_id[0];
    line_3[8] = curr_pack_id[1];
    //line3[8] = curr_pack_id[2];lcd.h
    
    //line3[9] = curr_pack_id[3];


    //next pack CAN address
    line_3[16] = next_pack_id[0];
    line_3[17] = next_pack_id[1];
    //line3[17] = next_can_addr[2];
    //line3[18] = next_can_addr[3];

    memcpy((void*)display_0, (void*) line_0, 20);
    memcpy((void*)display_1, (void*) line_1, 20);
    memcpy((void*)display_2, (void*) line_2, 20);
    memcpy((void*)display_3, (void*) line_3, 20);

    if( (PINB & 0x01) == 0x00){ // if the enter button is pressed
      break;					// didn't work correctly when button_enter bool was used 
    }
  }

  //CANADD_PACKINFO1 = CANADD_PACKINFO1;
  /* CANADD_PACKINFO2   = CANADD_PACKINFO1 + 1; */
  /* CANADD_CELLINFO    = CANADD_PACKINFO1 + 2; */
  //save to EEPROM
  /* eeprom_write_word((uint16_t*)EEPROM_CAN_ADDR1, addr_choice); */
  /* eeprom_write_word((uint16_t*)EEPROM_CAN_ADDR2, CANADD_PACKINFO2); */
  /* eeprom_write_word((uint16_t*)EEPROM_CAN_ADDR3, CANADD_CELLINFO); */

  /* CANADD_PACKINFO1 = eeprom_read_word((uint16_t*)EEPROM_CAN_ADDR1); */

  eeprom_write_byte((uint8_t*)EEPROM_PACK_ID, pack_num_choice);
  PACK_NUM = eeprom_read_byte((uint8_t*)EEPROM_PACK_ID);

  line_0[0] ='P'; 
  line_0[1] ='A';
  line_0[2] ='C';
  line_0[3] ='K';
  line_0[4] =' ';
  line_0[5] ='I';
  line_0[6] ='D';
  line_0[7] =' ';
  line_0[8] ='S';
  line_0[9] ='E';
  line_0[10]='T';
  line_0[11]='!';
  line_0[12]=' ';
  line_0[13]=' ';
  line_0[14]=' ';
  line_0[15]=' ';
  line_0[16]=' ';
  line_0[17]=' ';
  line_0[18]=' ';
  line_0[19]=' ';

  memcpy((void*)display_0, (void*) line_0, 20);
  memcpy((void*)display_1, (void*) line_1, 20);
  memcpy((void*)display_2, (void*) line_2, 20);
  memcpy((void*)display_3, (void*) line_3, 20);

  atomTimerDelay(100);

  return 0;

}

void set_num_cells(){

  //atomTimerDelay(700);

  unsigned char line_0[20] = {'S','E','T',' ','N','U','M','B','E','R',' ','O','F',' ','C','E','L','L','S',' '};
  unsigned char line_1[20] = {'U','P','/','D','O','W','N',' ','T','O',' ','C','H','A','N','G','E',' ',' ',' '};
  unsigned char line_2[20] = {'E','N','T','E','R',' ','T','O',' ','S','E','T',' ',' ',' ',' ',' ',' ',' ',' '};
  unsigned char line_3[20] = {'C','U','R','R','>',' ',' ',' ',' ',' ',' ','N','X','T','>',' ',' ',' ',' ',' '};

  memcpy((void*)display_0, (void*) line_0, 20);
  memcpy((void*)display_1, (void*) line_1, 20);
  memcpy((void*)display_2, (void*) line_2, 20);
  memcpy((void*)display_3, (void*) line_3, 20);

  atomTimerDelay(100);
	
  cell_num_choice = num_cells;
  sprintf(&curr_num_cells[0], "%02X", num_cells);
  sprintf(&next_num_cells[0], "%02X", cell_num_choice);

  atomTimerDelay(50);
	
  sel = 1;
  // choice for pack id: 1 - 0x7f = 1 - 127
  for(;;){
		
    if(button_up){
      //if(sel < 4){
	sel++;
	//}
      cell_num_choice = sel;
      
      /* if(cell_num_choice == 255){ */
      /* 	sel = 1; */
      /* 	pack_num_choice = sel; */
      /* } */
      sprintf(&next_num_cells[0], "%02X", cell_num_choice);
      button_up = false;
		
    }else if(button_down){
      sel--;
      if(sel == 0){
	sel = 255;
      }
      cell_num_choice = sel;
      sprintf(&next_num_cells[0], "%02X", cell_num_choice);
      button_down = false;
    }
		
    //displays var sel
    //should change when down is pressed
    //line1[17] = sel+48;

    //current pack CAN address  //asdf
    line_3[7] = curr_num_cells[0];
    line_3[8] = curr_num_cells[1];
    //line3[8] = curr_pack_id[2];lcd.h
    
    //line3[9] = curr_pack_id[3];


    //next pack CAN address
    line_3[16] = next_num_cells[0];
    line_3[17] = next_num_cells[1];
    //line3[17] = next_can_addr[2];
    //line3[18] = next_can_addr[3];

    memcpy((void*)display_0, (void*) line_0, 20);
    memcpy((void*)display_1, (void*) line_1, 20);
    memcpy((void*)display_2, (void*) line_2, 20);
    memcpy((void*)display_3, (void*) line_3, 20);

    if( (PINB & 0x01) == 0x00){ // if the enter button is pressed
      break;					// didn't work correctly when button_enter bool was used 
    }
  }

  //CANADD_PACKINFO1 = CANADD_PACKINFO1;
  /* CANADD_PACKINFO2   = CANADD_PACKINFO1 + 1; */
  /* CANADD_CELLINFO    = CANADD_PACKINFO1 + 2; */
  //save to EEPROM
  /* eeprom_write_word((uint16_t*)EEPROM_CAN_ADDR1, addr_choice); */
  /* eeprom_write_word((uint16_t*)EEPROM_CAN_ADDR2, CANADD_PACKINFO2); */
  /* eeprom_write_word((uint16_t*)EEPROM_CAN_ADDR3, CANADD_CELLINFO); */

  /* CANADD_PACKINFO1 = eeprom_read_word((uint16_t*)EEPROM_CAN_ADDR1); */

  eeprom_write_byte((uint8_t*)EEPROM_CELL_COUNT, cell_num_choice);
  num_cells = eeprom_read_byte((uint8_t*)EEPROM_CELL_COUNT);

  line_0[0] ='N'; 
  line_0[1] ='U';
  line_0[2] ='M';
  line_0[3] =' ';
  line_0[4] ='C';
  line_0[5] ='E';
  line_0[6] ='L';
  line_0[7] ='L';
  line_0[8] ='S';
  line_0[9] =' ';
  line_0[10]='S';
  line_0[11]='E';
  line_0[12]='T';
  line_0[13]='!';
  line_0[14]=' ';
  line_0[15]=' ';
  line_0[16]=' ';
  line_0[17]=' ';
  line_0[18]=' ';
  line_0[19]=' ';

  memcpy((void*)display_0, (void*) line_0, 20);
  memcpy((void*)display_1, (void*) line_1, 20);
  memcpy((void*)display_2, (void*) line_2, 20);
  memcpy((void*)display_3, (void*) line_3, 20);

  atomTimerDelay(100);

  //return 0;

}

/* unsigned char line0[20] = {'E','R','R','O','R',' ','I','N','F','O',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}; */
/* unsigned char line1[20] = {'A','C','T','I','V','E',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}; */
/* unsigned char line2[20] = {'F','A','U','L','T',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}; */
/* unsigned char line3[20] = {'V','A','L',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}; */

void display_error(){

  unsigned char line0[20] = {'E','R','R','O','R',' ','I','N','F','O',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
  unsigned char line1[20] = {'A','C','T','I','V','E',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
  unsigned char line2[20] = {'F','A','U','L','T',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
  unsigned char line3[20] = {'V','A','L',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};

  memcpy((void*)display_0, (void*) line0, 20);
  memcpy((void*)display_1, (void*) line1, 20);
  memcpy((void*)display_2, (void*) line2, 20);
  memcpy((void*)display_3, (void*) line3, 20);

  atomTimerDelay(100);

}

void disp_cell_info_screen(){

  unsigned char line0[20] = {'P','R','E','S','S',' ','E','N','T','E','R',' ','T','O',' ',' ',' ',' ',' ',' '};
  unsigned char line2[20] = {'D','I','S','P','L','A','Y',' ','C','E','L','L',' ','I','N','F','O',' ',' ',' '};
  unsigned char line1[20] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
  unsigned char line3[20] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};

  memcpy((void*)display_0, (void*) line0, 20);
  memcpy((void*)display_1, (void*) line1, 20);
  memcpy((void*)display_2, (void*) line2, 20);
  memcpy((void*)display_3, (void*) line3, 20);

  //atomTimerDelay(100);

}

void disp_cell_cal_screen(){

  unsigned char line0[20] = {'P','R','E','S','S',' ','E','N','T','E','R',' ','T','O',' ',' ',' ',' ',' ',' '};
  unsigned char line2[20] = {'D','I','S','P','L','A','Y',' ','C','E','L','L',' ',' ',' ',' ',' ',' ',' ',' '};
  unsigned char line1[20] = {'C','A','L','I','B','R','A','T','I','O','N',' ',' ',' ',' ',' ',' ',' ',' ',' '};
  unsigned char line3[20] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};

  memcpy((void*)display_0, (void*) line0, 20);
  memcpy((void*)display_1, (void*) line1, 20);
  memcpy((void*)display_2, (void*) line2, 20);
  memcpy((void*)display_3, (void*) line3, 20);

  //atomTimerDelay(100);

}

void disp_logged_states_screen(){

  unsigned char line0[20] = {'P','R','E','S','S',' ','E','N','T','E','R',' ','T','O',' ',' ',' ',' ',' ',' '};
  unsigned char line2[20] = {'D','I','S','P','L','A','Y',' ','L','O','G','G','E','D',' ',' ',' ',' ',' ',' '};
  unsigned char line1[20] = {'S','T','A','T','E','S',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
  unsigned char line3[20] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};

  memcpy((void*)display_0, (void*) line0, 20);
  memcpy((void*)display_1, (void*) line1, 20);
  memcpy((void*)display_2, (void*) line2, 20);
  memcpy((void*)display_3, (void*) line3, 20);

  //atomTimerDelay(100);

}


void display_logged_states(uint8_t state_num){

  unsigned char line0[20] = {'S','T','A','T','E',' ','L','O','G',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
  unsigned char line1[20] = {'S','T','A','T','E',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
  unsigned char line2[20] = {'T','I','M','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
  unsigned char line3[20] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};

  memcpy((void*)display_0, (void*) line0, 20);
  memcpy((void*)display_1, (void*) line1, 20);
  memcpy((void*)display_2, (void*) line2, 20);
  memcpy((void*)display_3, (void*) line3, 20);

  State disp_state;
  disp_state = recent_states[state_num];

  uint32_t disp_ts = state_ts[state_num];

  char* d = "DEAD";
  switch(disp_state){
  case chrg: d = "CHRG";
    break;
  case chrgd: d = "CHRGD";
    break;
  case lco: d = "LCO";
    break;
  case flt: d = "FLT"; line1[10] = flt_cnd.cond+48;//line0[10] = fault_code+48; TESTING, REVERT BACK 03292017
    break;
  case dead: d = "DEAD";
    break;
  case rdy: d = "RDY";
    break;
  case boot: d = "BOOT";
    break;
  }
		
  memcpy(line1+6,d, strlen(d)); // COPY INTO THE LINE

  uint32_t state_seconds = disp_ts/100; //100 system ticks per sec
  uint32_t state_minutes = (state_seconds/60);
  uint32_t state_hours = state_minutes/60;
  uint32_t state_days = state_hours/24;
  state_seconds = state_seconds%60;
  state_minutes = state_minutes%60;
  state_hours = state_hours%24;
  line2[19]= state_seconds%10+48;
  line2[18]= (state_seconds/10)%10+48;
  line2[17]= ':';
  line2[16]= (state_minutes)%10+48;
  line2[15]= (state_minutes/10)%10+48;
  line2[14]= ':';
  line2[13]= (state_hours)%10+48;
  line2[12]= (state_hours/10)%10+48;
  line2[11]= ':';
  line2[10]= (state_days)%10+48;
  line2[9]=  (state_days/10)%10+48;
  line2[8]=  (state_days/100)%10+48;

  state_seconds = (atomTimeGet()/100); //100 system ticks per sec
  state_minutes = (state_seconds/60);
  state_hours = state_minutes/60;
  state_days = state_hours/24;
  state_seconds = state_seconds%60;
  state_minutes = state_minutes%60;
  state_hours = state_hours%24;
  line3[19]= state_seconds%10+48;
  line3[18]= (state_seconds/10)%10+48;
  line3[17]= ':';
  line3[16]= (state_minutes)%10+48;
  line3[15]= (state_minutes/10)%10+48;
  line3[14]= ':';
  line3[13]= (state_hours)%10+48;
  line3[12]= (state_hours/10)%10+48;
  line3[11]= ':';
  line3[10]= (state_days)%10+48;
  line3[9]=  (state_days/10)%10+48;
  line3[8]=  (state_days/100)%10+48;

  
	
  memcpy((void*)display_0, (void*) line0, 20);
  memcpy((void*)display_1, (void*) line1, 20);
  memcpy((void*)display_2, (void*) line2, 20);
  memcpy((void*)display_3, (void*) line3, 20);

  //atomTimerDelay(100);


}


int8_t set_can_address(/*uint16_t can_address*/) {
	unsigned char line0[20] = {'S','E','T',' ','C','A','N',' ','A','D','D','R','E','S','S',' ',' ',' ',' ',' '};
	unsigned char line1[20] = {'U','P','/','D','O','W','N',' ','T','O',' ','C','H','A','N','G','E',' ',' ',' '};
	unsigned char line2[20] = {'E','N','T','E','R',' ','T','O',' ','S','E','T',' ',' ',' ',' ',' ',' ',' ',' '};
	unsigned char line3[20] = {'C','U','R','R','>','0','x',' ',' ',' ',' ','N','X','T','>','0','x',' ',' ',' '};
	
	addr_choice = CANADD_PACKINFO1;
	sprintf(&curr_can_addr[0], "%04X", CANADD_PACKINFO1);
	sprintf(&next_can_addr[0], "%04X", addr_choice);
	atomTimerDelay(50);
	
	sel = 0;
	for(;;){
		

		if(button_up){
			sel++;
			addr_choice = sel + 0x0500;
			sprintf(&next_can_addr[0], "%04X", addr_choice);
			if(addr_choice == 0x0600){
				sel = 0;
				addr_choice = 0x0500;
			}
			button_up = false;
		
		}else if(button_down){
			if(sel != 0){
				sel--;
				addr_choice = sel + 0x0500;
				sprintf(&next_can_addr[0], "%04X", addr_choice);
			}
			button_down = false;
		}
		
		//displays var sel
		//should change when down is pressed
		//line1[17] = sel+48;

		//current pack CAN address
		line3[7] = curr_can_addr[1];
		line3[8] = curr_can_addr[2];
		line3[9] = curr_can_addr[3];


		//next pack CAN address
		line3[16] = next_can_addr[1];
		line3[17] = next_can_addr[2];
		line3[18] = next_can_addr[3];

		memcpy((void*)display_0, (void*) line0, 20);
		memcpy((void*)display_1, (void*) line1, 20);
		memcpy((void*)display_2, (void*) line2, 20);
		memcpy((void*)display_3, (void*) line3, 20);

		if( (PINB & 0x01) == 0x00){ // if the enter button is pressed
			break;					// didn't work correctly when button_enter bool was used 
		}
	}

	//CANADD_PACKINFO1 = CANADD_PACKINFO1;
	CANADD_PACKINFO2   = CANADD_PACKINFO1 + 1;
	CANADD_CELLINFO    = CANADD_PACKINFO1 + 2;
	//save to EEPROM
	eeprom_write_word((uint16_t*)EEPROM_CAN_ADDR1, addr_choice);
	eeprom_write_word((uint16_t*)EEPROM_CAN_ADDR2, CANADD_PACKINFO2);
	eeprom_write_word((uint16_t*)EEPROM_CAN_ADDR3, CANADD_CELLINFO);

	CANADD_PACKINFO1 = eeprom_read_word((uint16_t*)EEPROM_CAN_ADDR1);

	line0[0] ='C'; 
	line0[1] ='A';
	line0[2] ='N',
	line0[3] =' ';
	line0[4] ='A';
	line0[5] ='D';
	line0[6] ='D';
	line0[7] ='R';
	line0[8] ='E';
	line0[9] ='S';
	line0[10]='S';
	line0[11]=' ';
	line0[12]='S';
	line0[13]='E';
	line0[14]='T';
	line0[15]='!';
	line0[16]=' ';
	line0[17]=' ';
	line0[18]=' ';
	line0[19]=' ';

	memcpy((void*)display_0, (void*) line0, 20);
	memcpy((void*)display_1, (void*) line1, 20);
	memcpy((void*)display_2, (void*) line2, 20);
	memcpy((void*)display_3, (void*) line3, 20);

	atomTimerDelay(100);

	//int8_t temp_num;

	//atomTimerDelay(700);
	//temp_num = set_pack_num();

	atomTimerDelay(100);
	return 0;
	

	//return temp_num;
}

