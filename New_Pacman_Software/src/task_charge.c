#include "task_charge.h"
#include "params.h"
#include "i2c.h"
#include "atomport.h"
#include "atom.h"
#include <avr/eeprom.h>

void task_charge_init(void){
	CHRG_DET = false;
	uint8_t i = 0;
	prev_pack_SOC = 0;

	for(i = 0; i<ams_board_count; i = i+1){
		cell_status[i] = 0;
	}
	atomMutexCreate(&A_mutex);
}

// called in task_config 
int8_t read_SOC(void){
	pack_SOC = eeprom_read_byte((uint8_t*)EEPROM_SOC);
	
	if((pack_SOC == 0x00) || (pack_SOC == 0xFF)) {
	 	 eeprom_write_byte((uint8_t*)EEPROM_SOC, 50);
	 	 pack_SOC = eeprom_read_byte((uint8_t*)EEPROM_SOC); 
	 }
	 return pack_SOC;
}
// called in task_config
void save_SOC(void){
	if(prev_pack_SOC != pack_SOC){
		prev_pack_SOC = pack_SOC;
		eeprom_write_byte((uint8_t*)EEPROM_SOC, pack_SOC);
	}
}

//This task integrates current to determine SOC.  It also monitors cell voltages to set bypass during charging.
void task_charge(uint32_t data) {
	int32_t last_tick  = 0;
	int32_t current_tick = 0;
	int32_t d_t;
	uint8_t i = 0;
	task_charge_init();
	for(;;) {

		watch_dog_list[WATCH_CHARGE]++;


	if(pack_state != boot){//wait 2 sec for all other tasks to start successfully
		if(pack_state == chrg){
			PORTA |= 0x30;//turn on charge relay and fan
		}
		else{
			if(pack_state == lco){
				PORTA |= 0x10;//turn on charge relay
			}else{
				PORTA &= ~(0x30);//turn off charge relay and fan
			}
		}
		// TODO change this logic to check for all cells to be at least 3700
		//if a cell voltage peaks or rolls off we know it is completely full/empty
		for(i = 0; i<ams_board_count; i = i+1){
			if((cell_V[i] > max_charge_cell_voltage) && CHRG_DET){//3700 mV cell voltage
			  if(cell_V[i] != 0xFFF6){
				pack_coulombs = MAX_COULOMBS;// * 10^-4 coulombs in a full pack
				pack_SOC = 100;
			  }
			}
		}
		// TODO remove or change to check for no current (<1A)
		for(i = 0; i<ams_board_count; i = i+1){
			if((cell_V[i] < (100*min_cell_voltage)) && pack_current < min_current){//2700 mV cell voltage and less than 1A
				pack_coulombs = 0;
				pack_SOC = 0;
			}
		}

		//integrate current
		current_tick = atomTimeGet();
		d_t = current_tick-last_tick; //diff in time between updates, in .01 sec
		atomMutexGet(&A_mutex,0);
		// TODO should this let negative numbers? We can do regeneration
		if(pack_coulombs - ((pack_current)*(d_t)/100) >= 0){//never let coulombs be negative
			pack_coulombs = pack_coulombs - (((pack_current)*(d_t))/100);
		}
		atomMutexPut(&A_mutex);
		last_tick = current_tick;
		//peaks and roll offs are the only way we say the pack is full or empty.  only update SOC if coulombs are >1% <99%
		if(pack_coulombs>(MAX_COULOMBS*.01) && pack_coulombs<(MAX_COULOMBS*.99)){//coulombs counted between 1 and 99 %
			pack_SOC= (uint16_t)(100.0 * (pack_coulombs / ((float)MAX_COULOMBS)));//
		}
	}
	}
}
