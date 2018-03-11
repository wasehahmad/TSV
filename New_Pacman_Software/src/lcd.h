#ifndef LCD_H
#define LCD_H

// standard library includes
#include <stdint.h>
#include <stdio.h>

// local includes
#include "params.h"

uint8_t cell;
const char* Pack_State_Strings[7];
void write_lcd(void);
void display_top(void);
void display_chst(void);
void display_cal1(void);
void display_cal1_voff(void);
void display_cal1_vslp(void);
void display_cal1_aoff(void);
void display_cal1_aslp(void);
void display_cal2(void);
void display_cell(uint8_t type);
void display_cell_cal(uint8_t cell);
void display_cell_cal_voff(uint8_t cell);
void display_cell_cal_vslp(uint8_t cell);
void display_cell_cal_toff(uint8_t cell);
void display_cell_cal_tslp(uint8_t cell);

//int8_t set_can_address(void);

//int8_t set_pack_num(void);

//void set_num_cells(void);

void display_error(void);

void wrong_password(void);
void lock_toggled(void);

void display_logged_states(uint8_t state_num);

void disp_cell_info_screen(void);
void disp_cell_cal_screen(void);
void disp_logged_states_screen(void);

void disp_invalid_addr(void);
uint8_t confirm_config(void);

void set_config_param(void);

void clear_screen(void);

volatile uint16_t addr_choice;
volatile uint8_t sel;

volatile uint8_t param_choice;
/* volatile uint8_t pack_num_choice; */

/* volatile uint8_t cell_num_choice; */

// Char arrays used to by sprintf()/itoa() in set_can_address & display_cell_cal()
// to display on LCD

char address[4];		// i2c address
/* char curr_can_addr[5];	// current CAN bus address */
/* char next_can_addr[5];	// next CAN bus address */
char off_result[5];		// cell voltage offset
char slp_result[5];		// cell voltage slpope

char curr_buff[2];
char next_buff[2];
char val_buff[2];

/* char curr_num_cells[2]; */
/* char next_num_cells[2]; */

/* char *line0; */
/* char *line1; */
/* char *line2; */
/* char *line3; */

unsigned char line0[20];
unsigned char line1[20];
unsigned char line2[20];
unsigned char line3[20];




#endif
