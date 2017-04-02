#include "task_can.h"
#include <avr/eeprom.h>

volatile uint16_t i;
volatile uint8_t num_cells;

void task_can_init(void){
	for(i = 0; i<7; i = i + 1){
		can_buff[i] = 0x00;//lets make a nice clean buffer
	}
	can_frame.dlc = 7;
	can_frame.pt_data = (uint8_t*)&can_buff;
	can_frame.cmd = CMD_TX; //This frame is for transmission only.  Make another for receiving if needed
	//can_frame_ctrl.rtr = false;
	//can_frame_ctrl.ide = false;
	can_frame.ctrl.ide = 0;
	//can_frame_id.std = CANADD_PACKINFO;
	//can_frame.id.std = CANADD_PACKINFO1;
	
	
	// READ CAN ADDRESSES FROM EEPROM

	//eventually want this to be configured by hte pushbuttons and lcd display, but for now this works.  Just change depending on which pack it is.
	
	
	 CANADD_PACKINFO1 = eeprom_read_word((uint16_t*)EEPROM_CAN_ADDR1);

	 if((CANADD_PACKINFO1 == 0x0000) || (CANADD_PACKINFO1 == 0xFFFF)) {
	 	 eeprom_write_word((uint16_t*)EEPROM_CAN_ADDR1, DEFAULT_CAN_ADDR1);
	 	 CANADD_PACKINFO1 = eeprom_read_word((uint16_t*)EEPROM_CAN_ADDR1); 
	 }

 	 CANADD_PACKINFO2 = eeprom_read_word((uint16_t*)EEPROM_CAN_ADDR2);

	 if((CANADD_PACKINFO2 == 0x0000) || (CANADD_PACKINFO2 == 0xFFFF)) {
	 	 eeprom_write_word((uint16_t*)EEPROM_CAN_ADDR2, DEFAULT_CAN_ADDR2);
	 	 CANADD_PACKINFO2 = eeprom_read_word((uint16_t*)EEPROM_CAN_ADDR2); 
	 }

	 CANADD_CELLINFO = eeprom_read_word((uint16_t*)EEPROM_CAN_ADDR3);

	 if((CANADD_CELLINFO == 0x0000) || (CANADD_CELLINFO == 0xFFFF)) {
	 	 eeprom_write_word((uint16_t*)EEPROM_CAN_ADDR3, DEFAULT_CAN_ADDR3);
	 	 CANADD_CELLINFO = eeprom_read_word((uint16_t*)EEPROM_CAN_ADDR3); 
	 }

	 PACK_NUM = eeprom_read_byte((uint8_t*)EEPROM_PACK_ID);

	 if((PACK_NUM == 0x00) || (PACK_NUM == 0xFF)) {
	 	 eeprom_write_byte((uint8_t*)EEPROM_PACK_ID, DEFAULT_PACK_NUM);
	 	 PACK_NUM = eeprom_read_byte((uint8_t*)EEPROM_PACK_ID); 
	 }

	 // DOING THIS FOR NOW, EVENTUALLY MAKE THIS CONFIGURABLE BY THE LCD DISPLAY AND PUSH BUTTONS:
	 num_cells = 7;
}

void task_can(uint32_t data){
	task_can_init();
	can_init(0);
	
	//uint16_t PACK_NUM = 0x001;
	//uint32_t system_time = 0;  // PROBABLY WANT TO USE AGAIN
	for(;;){	//loop forever
		


		// OLD:
		// can_buff[0] = pack_state;
		// can_buff[1] = pack_voltage >> 8;
		// can_buff[2] = pack_voltage & 0xFF;
		// can_buff[3] = pack_current >> 24 & 0xFF;
		// can_buff[4] = pack_current >> 16 & 0xFF;
		// can_buff[5] = pack_current >> 8 & 0xFF;
		// can_buff[6] = pack_current & 0xFF;
		// can_buff[7] = pack_SOC;
		// can_frame.dlc = 8;
		// can_frame.id.std = CANADD_PACKINFO1;
		// while(can_cmd(&can_frame) != CAN_CMD_ACCEPTED){
		// }
		// while(can_get_status(&can_frame) == CAN_STATUS_NOT_COMPLETED);
		// //atomTimerDelay(10);

		//NEW:



		// FIRST PACKET: PACK STATE ; PACK VOLTAGE ; PACK CURRENT ; PACK SOC

		can_frame.id.std = (PACK_NUM<<8) & 0x7FF;
		can_frame.dlc = 8;
		
		can_buff[0] = pack_state;
		
		can_buff[1] = pack_voltage >> 8;
		can_buff[2] = pack_voltage & 0xFF;

		can_buff[3] = pack_current >> 24 & 0xFF;
		can_buff[4] = pack_current >> 16 & 0xFF;
		can_buff[5] = pack_current >> 8 & 0xFF;
		can_buff[6] = pack_current & 0xFF;

		can_buff[7] = pack_SOC;
		
		while(can_cmd(&can_frame) != CAN_CMD_ACCEPTED){
		}
		while(can_get_status(&can_frame) == CAN_STATUS_NOT_COMPLETED);

	        // SECOND PACKET: PACK COULOMBS ; CELL 1 STATUS ; CELL 3 STATUS ; CELL 4 STATUS ...

		can_buff[0] = pack_coulombs>>24 & 0xFF;
		can_buff[1] = pack_coulombs>>16 & 0xFF;
		can_buff[2] = pack_coulombs>>8 & 0xFF;
		can_buff[3] = pack_coulombs & 0xFF;

		uint8_t packet_num = 1;
		uint8_t packet_offset = 4;
		uint8_t cell_num = 1;
		uint8_t bytes_left = 4;

		//SEND THE CELL STATUSES:
		while(cell_num <= num_cells){
		  while((bytes_left > 0) && (cell_num <= num_cells)){
		    can_buff[packet_offset] = cell_status[cell_num];
		    packet_offset++;
		    cell_num++;
		    bytes_left--;
		  }
		  if(bytes_left == 0){
		    //SEND THE PACKET:
		    can_frame.id.std = (PACK_NUM<<8 | packet_num) & 0x7FF;
		    can_frame.dlc = packet_offset;
		    while(can_cmd(&can_frame) != CAN_CMD_ACCEPTED){
		    }
		    while(can_get_status(&can_frame) == CAN_STATUS_NOT_COMPLETED);
		    packet_num++;
		    packet_offset = 0;
		    bytes_left = 8;
		  }
		}
		
		// FINISHED SENDING CELL STATUSES, NOW SEND CELL VOLTAGES:

		cell_num = 1;

		while(cell_num <= num_cells){
		  while((bytes_left > 1) && (cell_num <= num_cells)){
		    can_buff[packet_offset] = cell_V[cell_num] >> 8;
		    can_buff[packet_offset+1] = cell_V[cell_num] & 0xFF;
		    packet_offset = packet_offset+2;
		    cell_num++;
		    bytes_left = bytes_left - 2;
		  }
		  if(bytes_left <= 1){
		    //SEND THE PACKET:
		    can_frame.id.std = (PACK_NUM<<8 | packet_num) & 0x7FF;
		    can_frame.dlc = packet_offset;
		    while(can_cmd(&can_frame) != CAN_CMD_ACCEPTED){
		    }
		    while(can_get_status(&can_frame) == CAN_STATUS_NOT_COMPLETED);
		    packet_num++;
		    packet_offset = 0;
		    bytes_left = 8;
		  }
		}

		// FINISHED SENDING CELL VOLTAGES, NOW SEND CELL TEMPERATURES:

		cell_num = 1;

		while(cell_num <= num_cells){
		  while((bytes_left > 1) && (cell_num <= num_cells)){
		    can_buff[packet_offset] = cell_T[cell_num] >> 8;
		    can_buff[packet_offset+1] = cell_T[cell_num] & 0xFF;
		    packet_offset = packet_offset+2;
		    cell_num++;
		    bytes_left = bytes_left - 2;
		  }
		  if(bytes_left <= 1){
		    //SEND THE PACKET:
		    can_frame.id.std = (PACK_NUM<<8 | packet_num) & 0x7FF;
		    can_frame.dlc = packet_offset;
		    while(can_cmd(&can_frame) != CAN_CMD_ACCEPTED){
		    }
		    while(can_get_status(&can_frame) == CAN_STATUS_NOT_COMPLETED);
		    packet_num++;
		    packet_offset = 0;
		    bytes_left = 8;
		  }
		}

		/* can_frame.dlc = 2; */
		/* can_frame.id.std = (PACK_NUM<<8 | 0x001) & 0x7FF; */
		/* while(can_cmd(&can_frame) != CAN_CMD_ACCEPTED){ */
		/* } */
		/* while(can_get_status(&can_frame) == CAN_STATUS_NOT_COMPLETED); */

		// PACK CURRENT
		/* can_buff[0] = pack_current >> 24 & 0xFF; */
		/* can_buff[1] = pack_current >> 16 & 0xFF; */
		/* can_buff[2] = pack_current >> 8 & 0xFF; */
		/* can_buff[3] = pack_current & 0xFF; */
		/* can_frame.dlc = 4; */
		/* can_frame.id.std = (PACK_NUM<<8 | 0x002) & 0x7FF; */
		/* while(can_cmd(&can_frame) != CAN_CMD_ACCEPTED){ */
		/* } */
		/* while(can_get_status(&can_frame) == CAN_STATUS_NOT_COMPLETED); */

		// PACK SOC
		/* can_buff[0] = pack_SOC; */
		/* can_frame.dlc = 1; */
		/* can_frame.id.std = (PACK_NUM<<8 | 0x003) & 0x7FF; */
		/* while(can_cmd(&can_frame) != CAN_CMD_ACCEPTED){ */
		/* } */
		/* while(can_get_status(&can_frame) == CAN_STATUS_NOT_COMPLETED); */

		// PACK COULOMBS
		/* can_buff[0] = pack_coulombs>>24 & 0xFF; */
		/* can_buff[1] = pack_coulombs>>16 & 0xFF; */
		/* can_buff[2] = pack_coulombs>>8 & 0xFF; */
		/* can_buff[3] = pack_coulombs & 0xFF; */
		/* can_frame.dlc = 4; */
		/* can_frame.id.std = (PACK_NUM<<8 | 0x004) & 0x7FF; */
		/* while(can_cmd(&can_frame) != CAN_CMD_ACCEPTED){ */
		/* } */
		/* while(can_get_status(&can_frame) == CAN_STATUS_NOT_COMPLETED); */

		///////////////////////////////////////////////////////////////////////////////////////
		
		


		//atomTimerDelay(10);
		
		// OLD:
		// system_time = atomTimeGet();
		// can_buff[0] = system_time>>24 & 0xFF;
		// can_buff[1] = system_time>>16 & 0xFF;
		// can_buff[2] = system_time>>8 & 0xFF;
		// can_buff[3] = system_time & 0xFF;
		// can_buff[4] = pack_coulombs>>24 & 0xFF;
		// can_buff[5] = pack_coulmobs>>16 & 0xFF;
		// can_buff[6] = pack_coulombs>>8 & 0xFF;
		// can_buff[7] = pack_coulombs & 0xFF;
		// can_frame.dlc = 8;
		// can_frame.id.std = CANADD_PACKINFO2;
		// while(can_cmd(&can_frame) != CAN_CMD_ACCEPTED){
		// }
		// while(can_get_status(&can_frame) == CAN_STATUS_NOT_COMPLETED);
		// //atomTimerDelay(50);
		
		// OLD:
		// for(i = 0; i < 7; i = i +1){
		// 	can_buff[0] = i;
		// 	can_buff[1] = cell_status[i];
		// 	can_buff[2] = cell_V[i] >> 8;
		// 	can_buff[3] = cell_V[i] & 0xFF;
		// 	can_buff[4] = cell_T[i] >> 8;
		// 	can_buff[5] = cell_T[i] & 0xFF;
		// 	can_buff[6] = 0;
		// 	can_frame.dlc = 6;
		// 	can_frame.id.std = CANADD_CELLINFO;
		// 	while(can_cmd(&can_frame) != CAN_CMD_ACCEPTED){
		// 	}
		// 	while(can_get_status(&can_frame) == CAN_STATUS_NOT_COMPLETED);
			
		// }

		// NEW:
		// iterate for each cell
		/* for(i = 0; i < 7; i = i +1){ */
		/* 	can_buff[0] = cell_status[i]; */
		/* 	can_frame.dlc = 1; */
		/* 	can_frame.id.std = (PACK_NUM<<8 | 0x010 | i) & 0x7FF; */
		/* 	while(can_cmd(&can_frame) != CAN_CMD_ACCEPTED){ */
		/* 	} */
		/* 	while(can_get_status(&can_frame) == CAN_STATUS_NOT_COMPLETED); */

		/* 	can_buff[0] = cell_V[i] >> 8; */
		/* 	can_buff[1] = cell_V[i] & 0xFF; */
		/* 	can_frame.dlc = 2; */
		/* 	can_frame.id.std = (PACK_NUM<<8 | 0x020 | i) & 0x7FF; */
		/* 	while(can_cmd(&can_frame) != CAN_CMD_ACCEPTED){ */
		/* 	} */
		/* 	while(can_get_status(&can_frame) == CAN_STATUS_NOT_COMPLETED); */

		/* 	can_buff[0] = cell_T[i] >> 8; */
		/*  	can_buff[1] = cell_T[i] & 0xFF; */
		/* 	can_frame.dlc = 2; */
		/* 	can_frame.id.std = (PACK_NUM<<8 | 0x030 | i) & 0x7FF; */
		/* 	while(can_cmd(&can_frame) != CAN_CMD_ACCEPTED){ */
		/* 	} */
		/* 	while(can_get_status(&can_frame) == CAN_STATUS_NOT_COMPLETED); */

			
		/* } */



////////////////////////////////////////////////////////////////////////

		atomTimerDelay(100);  ///MARTY CHANGE - delay 1s (supposedly)

	}//end of loop

}
