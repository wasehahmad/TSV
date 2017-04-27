#include "config.h"

#include <util/delay.h>
#include <string.h>

#include "i2c_lcd/i2c_lcd.h"
#include "atmel/TWI_Master.h"

void lcd_putc(struct i2c_lcd *lcd, char character) {
	uint8_t control = LCD_RS | ((lcd->backlight_status) ? LCD_BACKLIGHT : 0);
	uint8_t byte = (uint8_t)character;
	_lcd_write(lcd, control, byte);
}

void _lcd_write(struct i2c_lcd *lcd, uint8_t control, uint8_t byte){
	// calculate low & high nibbles
	uint8_t nibble_high = (byte & 0xF0) >> 4;
	uint8_t nibble_low = (byte & 0x0F);
	
	// local var, describes 8-bit i2c expander state
	uint8_t lcd_io;
	
	// update upper 4 bits (D7-D4), write
	lcd_io = control | (nibble_high << 4);
	_lcd_command(lcd, lcd_io);
	
	// update upper 4 bits (D7-D4), write
	lcd_io = control | (nibble_low << 4);
	_lcd_command(lcd, lcd_io);
}

void _lcd_command(struct i2c_lcd *lcd, uint8_t lcd_io) {
	// write lcd_io (no EN signal)
	_lcd_i2c_expand(lcd, lcd_io & ~(1 << LCD_EN));
	_delay_us(LCD_DELAY_BUSY_FLAG);
	
	// write lcd_io (w/ EN signal)
	_lcd_i2c_expand(lcd, lcd_io | LCD_EN);
	_delay_us(LCD_DELAY_ENABLE_PULSE);
	
	// write lcd_io (no EN signal)
	// TODO optimization? remove this, let en pulse stagnate
	// might work, might not work... try to find out
	_lcd_i2c_expand(lcd, lcd_io);
}

//Initialize the I2C LCD and Controller
void lcd_init(struct i2c_lcd *lcd, uint8_t addr, uint8_t cols, uint8_t rows){
	// SEE PAGE 45/46 FOR INITIALIZATION SPECIFICATION!
	// Controller: Hitachi HD44780
	// Datasheet: https://www.sparkfun.com/datasheets/LCD/HD44780.pdf
	
	lcd->i2c_address = addr;
	lcd->backlight_status = 1;
	
	// at least 15ms are required after power rises above 4.5V
	_delay_us(LCD_DELAY_BOOTUP);
	
	// set interface to 8-bit mode 1/3
	_lcd_command(lcd, LCD_FUNCTIONSET | LCD_8BITMODE);
	_delay_us(LCD_DELAY_INIT);
	
	// set interface to 8-bit mode 2/3
	_lcd_command(lcd, LCD_FUNCTIONSET | LCD_8BITMODE);
	_delay_us(LCD_DELAY_INIT_REP);
	
	// set interface to 8-bit mode 3/3
	_lcd_command(lcd, LCD_FUNCTIONSET | LCD_8BITMODE);
	_delay_us(LCD_DELAY_INIT_REP);
	
	// finally, set interface to 4-bit mode
	_lcd_command(lcd, LCD_FUNCTIONSET | LCD_4BITMODE);
	_delay_us(LCD_DELAY_INIT_4BIT);
	
	// var holds command flags, for readability
	uint8_t flags;
	
	// set interface to 4-bit mode again, font/lines too
	flags = (rows > 1) ? (LCD_4BITMODE | LCD_2LINE | LCD_5x8DOTS) : 
			(LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS);
	_lcd_write(lcd, LCD_NONE, LCD_FUNCTIONSET | flags);
	_delay_us(LCD_DELAY_INIT_4BIT);
	
	// turn display off, it is about to be cleared
	flags = LCD_DISPLAYOFF | LCD_CURSORON | LCD_BLINKON;
	_lcd_write(lcd, LCD_NONE, LCD_DISPLAYCONTROL| flags);
	_delay_us(LCD_DELAY_BUSY_FLAG);
	
	// clear the display
	_lcd_write(lcd, LCD_NONE, LCD_CLEARDISPLAY);
	_delay_us(LCD_DELAY_BUSY_FLAG);
	
	// put the lcd into left-entry/cursor-increment modes
	flags = LCD_ENTRYLEFT | LCD_ENTRYINCREMENT;
	_lcd_write(lcd, LCD_BACKLIGHT, LCD_ENTRYMODESET | flags);
	_delay_us(LCD_DELAY_BUSY_FLAG);
	//        _delay_us(LCD_DELAY_BOOTUP);
	//        
	//        _lcd_write(lcd, LCD_NONE, 0x33);
	//        _delay_us(LCD_DELAY_INIT);
	//        
	//        
	//        _lcd_write(lcd, LCD_NONE, 0x32);
	//        _delay_us(LCD_DELAY_INIT_4BIT);
	//        
	//        _lcd_write(lcd, LCD_NONE, 0x28);
	//        _delay_us(LCD_DELAY_BUSY_FLAG);
	//        
	//        _lcd_write(lcd, LCD_NONE, 0x0C);
	//        _delay_us(LCD_DELAY_BUSY_FLAG);
	//        
	//        _lcd_write(lcd, LCD_NONE, 0x06);
	//        _delay_us(LCD_DELAY_BUSY_FLAG);
	//        
	//        _lcd_write(lcd, LCD_NONE, 0x01);
	_delay_us(LCD_DELAY_CLEAR);
	
}

void lcd_clear(struct i2c_lcd *lcd){
	uint8_t control = LCD_NONE | ((lcd->backlight_status) ? LCD_BACKLIGHT : 0);
	_lcd_write(lcd, control, LCD_CLEARDISPLAY);
}

void lcd_home(struct i2c_lcd *lcd){
	uint8_t control = LCD_NONE | ((lcd->backlight_status) ? LCD_BACKLIGHT : 0);
	_lcd_write(lcd, control, LCD_RETURNHOME);
}

void lcd_display_on(struct i2c_lcd *lcd) {
	lcd->displ_ctrl_flags |= LCD_DISPLAYON;
	uint8_t control = LCD_NONE | ((lcd->backlight_status) ? LCD_BACKLIGHT : 0);
	uint8_t command = LCD_DISPLAYCONTROL | lcd->displ_ctrl_flags;
	_lcd_write(lcd, control, command);
}

void lcd_display_off(struct i2c_lcd *lcd) {
	lcd->displ_ctrl_flags &= ~(LCD_DISPLAYON);
	
	uint8_t control = LCD_NONE | ((lcd->backlight_status) ? LCD_BACKLIGHT : 0);
	uint8_t command = LCD_DISPLAYCONTROL | lcd->displ_ctrl_flags;
	_lcd_write(lcd, control, command);
}

void lcd_blink_on(struct i2c_lcd *lcd) {
	lcd->displ_ctrl_flags |= LCD_BLINKON;
	
	uint8_t control = LCD_NONE | ((lcd->backlight_status) ? LCD_BACKLIGHT : 0);
	uint8_t command = LCD_DISPLAYCONTROL | lcd->displ_ctrl_flags;
	_lcd_write(lcd, control, command);
}

void lcd_blink_off(struct i2c_lcd *lcd) {
	lcd->displ_ctrl_flags &= ~(LCD_BLINKON);
	
	uint8_t control = LCD_NONE | ((lcd->backlight_status) ? LCD_BACKLIGHT : 0);
	uint8_t command = LCD_DISPLAYCONTROL | lcd->displ_ctrl_flags;
	_lcd_write(lcd, control, command);
}
void lcd_cursor_on(struct i2c_lcd *lcd) {
	lcd->displ_ctrl_flags |= LCD_CURSORON;
	
	uint8_t control = LCD_NONE | ((lcd->backlight_status) ? LCD_BACKLIGHT : 0);
	uint8_t command = LCD_DISPLAYCONTROL | lcd->displ_ctrl_flags;
	_lcd_write(lcd, control, command);
}

void lcd_cursor_off(struct i2c_lcd *lcd) {
	lcd->displ_ctrl_flags &= ~(LCD_CURSORON);
	
	uint8_t control = LCD_NONE | ((lcd->backlight_status) ? LCD_BACKLIGHT : 0);
	uint8_t command = LCD_DISPLAYCONTROL | lcd->displ_ctrl_flags;
	_lcd_write(lcd, control, command);
}

void lcd_backlight_off(struct i2c_lcd *lcd) {
	lcd->backlight_status = 0;
	_lcd_i2c_expand(lcd, LCD_NONE);
}
	
void lcd_backlight_on(struct i2c_lcd *lcd) {
	lcd->backlight_status = 1;
	_lcd_i2c_expand(lcd, LCD_BACKLIGHT);
}
	
//Below is code for printing onto the lcd
void lcd_puts(struct i2c_lcd *lcd, char *buffer)
{
	for(uint8_t i=0;i<(uint8_t)strlen(buffer);i++)
			lcd_putc(lcd, buffer[i]);
}

void _lcd_i2c_expand(struct i2c_lcd *lcd, uint8_t data) {
	uint8_t msg[2] = {(lcd->i2c_address), data}; 
	TWI_Start_Transceiver_With_Data(msg, 2);	
}
