#include "task_config.h"
#include "params.h"

#include "i2c.h"
#include <avr/eeprom.h>
#include "task_charge.h"

#include "atom.h"

//config sets initial state and SOC and monitors params for state change
void task_config(uint32_t data) {
	// cell_Voff[0] = 6;
	// cell_Voff[1] = 4;
	// cell_Voff[2] = 12;
	// cell_Voff[3] = -7;
	// cell_Voff[4] = -27;
	// cell_Voff[5] = -7;
	// cell_Voff[6] = -8;
	// cell_Vslp[0] = 1;
	// cell_Vslp[1] = 0.989;
	// cell_Vslp[2] = 1.001;
	// cell_Vslp[3] = 1.001;
	// cell_Vslp[4] = 1.008;
	// cell_Vslp[5] = 0.996;
	// cell_Vslp[6] = 1.014;
	cell_Toff[0] = 62;
	cell_Toff[1] = 70;
	cell_Toff[2] = 43;
	cell_Toff[3] = 57;
	cell_Toff[4] = 32;
	cell_Toff[5] = 49;
	cell_Toff[6] = 30;
	cell_Tslp[0] = 0.749;
	cell_Tslp[1] = 0.699;
	cell_Tslp[2] = 0.835;
	cell_Tslp[3] = 0.747;
	cell_Tslp[4] = 0.868;
	cell_Tslp[5] = 0.786;
	cell_Tslp[6] = 0.894;
	
	struct cal_data cal;


	//?
	flt_cnd.active = 0;
	flt_cnd.cond = 0;
	flt_cnd.val = 0;
	flt_cnd.area = 0;

	for(int i = 0; i < ams_board_count; i++) {
		cal = ams_cal(ams_board_addr[i]);

		cell_Vslp[i] = cal.slope;
		cell_Voff[i] = cal.offset;
	}

	pack_state = boot;
	//pack_coulombs = (uint32_t)(MAX_COULOMBS/2);//50% 

	pack_SOC = read_SOC();//(uint16_t)(10000.0 * pack_coulombs / ((float)MAX_COULOMBS));
	pack_coulombs = (uint32_t)(MAX_COULOMBS*((float)pack_SOC/100));
	save_SOC();
	uint8_t i = 0;
	for(;;) {
		save_SOC();
		//Detect Fault in all states
		for(i = 0; i<ams_board_count; i = i+1){//if communication with an AMS board is lost, these values are out of range
			if(cell_T[i] > 600){//60.0 deg C cell temp
				pack_state = flt;
				fault_code = 0;

				flt_cnd.active = 1;
				flt_cnd.cond = 0;
				flt_cnd.val = cell_T[i];
				flt_cnd.area = i;
			}
			if(cell_V[i] > 4000){// || (cell_V[i] <2000)){//>4000 mV or <2000 mV cell voltage //**** cell_V < 2000 uncommented 03292017
				pack_state = flt;
				fault_code = 1;

				flt_cnd.active = 1;
				flt_cnd.cond = 1;
				flt_cnd.val = cell_V[i];
				flt_cnd.area = i;
			}
		}
		if(pack_voltage > 20800){//20800 * .00125 mV/bit = 26 V
			pack_state = flt;
			fault_code = 2;

			flt_cnd.active = 1;
			flt_cnd.cond = 2;
			flt_cnd.val = pack_voltage;
			flt_cnd.area = 0;
		}
		if(pack_state != flt){//then determine the proper state
			switch(pack_state){
				case boot://we've booted and no fault
					atomTimerDelay(200);//wait one sec before ready
					pack_state = rdy;
					break; 
				case rdy:
					if(pack_SOC <1){//001.00 %
						pack_state = dead;
					}else if(CHRG_DET){
						pack_state = chrg;
					}else if(LOW_DET){
						pack_state = lco;
					}
					break;
				case dead:
					if(CHRG_DET){
						pack_state = chrg;
					}
					break;
				case chrg:
					if(!CHRG_DET){
						pack_state = rdy;
					}else if(pack_SOC>=100){//100.00%
						pack_state = chrgd;
					}
					break;
				case chrgd:
					if(!CHRG_DET){
						pack_state = rdy;
					}
					break;
				case lco:
					if(!LOW_DET){
						pack_state = rdy;
					}else if(pack_SOC < 1){//001.00%
						pack_state = dead;
					}
					break;
				default:
					pack_state = flt;
					break;
			}
		}else{//check if the fault is cleared
			State temp = rdy;
			flt_cnd.active = 0;
			for(i = 0; i<ams_board_count; i = i+1){//if communication with an AMS board is lost, these values are out of range
				if(cell_T[i] > 600){//60.0 deg C cell temp
					temp = flt;
					fault_code = 0;
					flt_cnd.active = 1;
				}
				if(cell_V[i] > 4000){// || (cell_V[i] <2000)){//>4000 mV or <2000 mV cell voltage
					temp = flt;
					fault_code = 1;
					flt_cnd.active = 1;
				}
			}
			if(pack_voltage > 20800){//20800 * .00125 mV/bit = 26 V
				temp = flt;
				fault_code = 2;
				flt_cnd.active = 1;
			}
			pack_state = temp; // COMMENTED 03092017 --> re-un-commented 03292017
		}
		
		//atomTimerDelay(10);
	}
}
