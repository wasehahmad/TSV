#ifndef I2C_LCD_H
#define I2C_LCD_H
// ORGINGAL LIBRARY CAN BE FOUND HERE...
// http://www.dfrobot.com/image/data/TOY0046/LiquidCrystal_I2Cv1-1.rar

#include <stdint.h>

// lcd commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for LCD_ENTRYMODESET
#define LCD_ENTRYLEFT 0x02 //TODO Check me
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYINCREMENT 0x01 //TODO Check me
#define LCD_ENTRYDECREMENT 0x00

// flags for LCD_DISPLAYCONTROL
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for LCD_CURSORSHIFT
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for LCD_FUNCTIONSET
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

// flag values/locations
#define LCD_NONE 0x00
#define LCD_RS 0x01
#define LCD_RW 0x02
#define LCD_EN 0x04
#define LCD_BACKLIGHT 0x08

// lcd delay lengths
#define LCD_DELAY_BOOTUP 16000
#define LCD_DELAY_INIT 5000
#define LCD_DELAY_INIT_REP 100
#define LCD_DELAY_INIT_4BIT 100     
#define LCD_DELAY_BUSY_FLAG 50
#define LCD_DELAY_ENABLE_PULSE 5
#define LCD_DELAY_CLEAR  500

// lcd structure for state storage
struct i2c_lcd {
	uint8_t i2c_address;
	
	uint8_t backlight_status : 1;
	uint8_t entry_mode_flags : 2;
	uint8_t displ_ctrl_flags : 3;
	uint8_t shift_ctrl_flags : 2;
	uint8_t funct_ctrl_flags : 3;
};

// character placement functions
void lcd_putc(struct i2c_lcd *lcd, char character);
void lcd_puts(struct i2c_lcd *lcd, char *buffer);

// lcd control functions
void lcd_init(struct i2c_lcd *lcd, uint8_t addr, uint8_t cols, uint8_t rows);
void lcd_clear(struct i2c_lcd *lcd);
void lcd_home(struct i2c_lcd *lcd);
void lcd_display_on(struct i2c_lcd *lcd);
void lcd_display_off(struct i2c_lcd *lcd);
void lcd_blink_on(struct i2c_lcd *lcd);
void lcd_blink_off(struct i2c_lcd *lcd);
void lcd_cursor_on(struct i2c_lcd *lcd);
void lcd_cursor_off(struct i2c_lcd *lcd);
void lcd_backlight_off(struct i2c_lcd *lcd);
void lcd_backlight_on(struct i2c_lcd *lcd);

//void lcd_autoscroll_on(struct i2c_lcd *lcd);
//void lcd_autoscroll_off(struct i2c_lcd *lcd); 
//void lcd_shift_left(struct i2c_lcd *lcd);
//void lcd_shift_right(struct i2c_lcd *lcd);
//
//void lcd_movecursor_left(struct i2c_lcd *lcd);
//void lcd_movecursor_right(struct i2c_lcd *lcd);
//void lcd_print_left(struct i2c_lcd *lcd);
//void lcd_print_right(struct i2c_lcd *lcd);
//void lcd_load_char(struct i2c_lcd *lcd, uint8_t location, uint8_t charmap[]);
//void lcd_set_cursor(struct i2c_lcd *lcd, uint8_t row, uint8_t col);

// private i2c/lcd command send functions
void _lcd_i2c_expand(struct i2c_lcd *lcd, uint8_t data);
void _lcd_write(struct i2c_lcd* lcd, uint8_t control, uint8_t byte);
void _lcd_command(struct i2c_lcd *lcd, uint8_t val);
#endif //I2C_LCD_H
