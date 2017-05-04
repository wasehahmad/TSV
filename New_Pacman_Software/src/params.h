#ifndef PARAMS_H
#define PARAMS_H

// standard library includes
#include <stdint.h>
#include "atom.h"
#include "config.h"
#include "atomqueue.h"
#include "atomutils.h"
#include "atomport.h"
#include "atmel/can_lib.h"
#include "atommutex.h"


//SOFTWARE VERSION (based on commit number in gitlab)
#define version 0.16

// LCD values
#define EN_LOW	0x08

#define NUM_CONFIG_PARAMS 7
#define PASSWORD 0xFF

volatile uint8_t config_addr[NUM_CONFIG_PARAMS];


//4 arrays for the 4 lines on the LCD
unsigned char display_0[20];
unsigned char display_1[20];
unsigned char display_2[20];
unsigned char display_3[20];

//typedef enum {false,true} bool;  stdbool.h is included in can_lib.h so this is no longer necessary.
typedef enum {boot,chrg,chrgd,lco,flt,dead,rdy} State; //mirrored values in VSCADA
volatile uint8_t fault_code;

//adding 04012017
struct flt_cond {
  uint8_t active;
  uint8_t cond;
  uint8_t area;
  uint16_t val;
};

/* struct display_time { */
/*   uint32_t sys_seconds; */
/*   uint32_t sys_minutes; */
/*   uint32_t sys_hours; */
/*   uint32_t sys_days; */
/* }; */

volatile struct flt_cond flt_cnd;


//various parameters that will be displayed on the LCD
volatile int16_t shunt_voltage;  //part of pack current calc
volatile int16_t pack_voltage;
volatile int32_t pack_current;
volatile int32_t adc_value;
volatile uint8_t prev_pack_SOC;
volatile uint8_t pack_SOC;
volatile int32_t pack_coulombs;
volatile uint16_t cell_V[7];
volatile uint16_t cell_T[7];
volatile uint8_t cell_status[7];
volatile State pack_state;
volatile bool sloop_state;
volatile bool CHRG_DET;
volatile bool LOW_DET;
volatile bool button_up;
volatile bool button_down;
volatile bool button_enter; // Is always high for some reason

volatile uint8_t num_cells;

volatile uint8_t locked;

// NEED TO LOG RECENT STATE TRANSITIONS AND TIMESTAMPS:
volatile State recent_states[5];
volatile uint32_t state_ts[5];
//volatile struct display_time state_ts[5];

volatile uint32_t sleep_time;

volatile uint16_t CANADD_PACKINFO1;
volatile uint16_t CANADD_PACKINFO2;
volatile uint16_t CANADD_CELLINFO;
volatile uint8_t  PACK_NUM;


//Flags for lcd message and bypass selection timing
volatile bool lcd_flag;
volatile bool bypass_flag;

volatile bool lcd_active;

//Calibration factors
#define pack_Voff				-0.3
#define pack_ametes_Aoff  		.6775//amps
#define pack_INA226_Aoff 		-0.00886//amps
#define pack_Vslp				1.014
#define pack_ametes_Aslp 		107.4977// A/V
#define pack_INA226_Aslp		0.9636 //none
volatile uint16_t cell_Voff[7];
volatile uint16_t cell_Toff[7];
volatile uint16_t cell_Vslp[7];
volatile float cell_Tslp[7];


//CAN parameters
// #define CANADD_PACKINFO1  0x0500  //additional packs should be at 0x0510, 0x520, 0x0530
// #define CANADD_PACKINFO2  0x0501  //additional packs should be at 0x0511, 0x521, 0x0531
// #define CANADD_CELLINFO   0x0502  //additional packs should be at 0x0512, 0x522, 0x0532
volatile uint8_t can_buff[8];
st_cmd_t can_frame;
volatile can_ctrl_t can_frame_ctrl;
volatile can_id_t can_frame_id;

//SOC parameters
#define MAX_COULOMBS  216000000 // * 10^-3 coulombs in a full pack

//Mutex to prevent integration of a bad current value
ATOM_MUTEX A_mutex;

//EEPROM Parameters
/* #define DEFAULT_CAN_ADDR1 	0x0500 	 */
/* #define DEFAULT_CAN_ADDR2 	0x0501 	 */
/* #define DEFAULT_CAN_ADDR3 	0x0502 */
#define DEFAULT_PACK_NUM 	0x01
#define DEFAULT_NUM_CELLS       7

#define DEFAULT_MAX_CELL_TEMP 0x3C
#define DEFAULT_MAX_CELL_VOLTAGE 0x28
#define DEFAULT_SCREEN_RESET_TIME 0x0F
#define DEFAULT_SCREEN_SLEEP_TIME 0x78

volatile uint8_t max_cell_voltage;
volatile uint8_t max_cell_temp;
volatile uint8_t screen_reset_time;
volatile uint8_t screen_sleep_time;


#define EEPROM_SOC  		1		// location in memory of last recorded State of Charge
#define EEPROM_LOCK             2               // location in memory of the lock state
#define EEPROM_MAX_CELL_TEMP    3
#define EEPROM_MAX_CELL_VOLTAGE 4
#define EEPROM_SCREEN_RESET_TIME 5
#define EEPROM_SCREEN_SLEEP_TIME 6
#define EEPROM_PACK_ID          8               // location in memory of the pack id
#define EEPROM_CELL_COUNT       9               // location in memory of the number of cells beign used



/* #define EEPROM_CAN_ADDR1	2		// location in memory of CAN address for CANADD_PACKINFO1 */
/* #define EEPROM_CAN_ADDR2	4		// location in memory of CAN address for CANADD_PACKINFO2 */
/* #define EEPROM_CAN_ADDR3	6		// location in memory of CAN address for CANADD_CELLINFO */

/*
#define EEPROM_PACK_V_OFF  	9
#define EEPROM_PACK_V_SLP 	11
#define EEPROM_AMETES_AOFF	13
#define EEPROM_AMETES_ASLP 	15
#define EEPROM_INA226_ASLP 	17
#define EEPROM_INA226_ASLP 	19
*/
#endif
