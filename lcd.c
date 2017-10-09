#include "lcd.h"

#include <avr/io.h>
#include <util/delay.h>


/* ==== ==== ==== for LCD ==== ==== ==== */
void lcd_init (void)
{
	_delay_ms(15);
	lcd_out(0x30, 0);
	_delay_ms(5);
	lcd_out(0x30, 0);
	_delay_ms(1);
	lcd_out(0x30, 0);
	_delay_ms(1);
	lcd_out(0x20, 0);
	_delay_ms(1);
	lcd_cmd(0x28);
	lcd_cmd(0x08);
	lcd_cmd(0x0c);
	lcd_cmd(0x06);
	lcd_cmd(0x02);
	lcd_cmd(0x01);
}

void lcd_out(const char code_, const char rs_)
{
	LCD_PORT = (code_ & 0xF0) | (LCD_PORT & 0x0F);
	if (rs_ == 0) LCD_PORT = LCD_PORT & ~LCD_RS;
	else          LCD_PORT = LCD_PORT |  LCD_RS;
	_delay_ms(1);
	LCD_PORT = LCD_PORT | LCD_E;
	_delay_ms(1);
	LCD_PORT = LCD_PORT & ~LCD_E;
}

void lcd_cmd(const char cmd_)
{
	lcd_out(cmd_, 0);
	lcd_out(cmd_<<4, 0);
	_delay_ms(2);
}

void lcd_data(const char data_)
{
	lcd_out(data_, 1);
	lcd_out(data_<<4, 1);
	_delay_ms(0.5);
}

void lcd_pos(const char line_, const char col_)
{
	if (line_ == 1) lcd_cmd(0x80 + col_ - 1);
	else if (line_ == 2) lcd_cmd(0xC0 + col_ - 1);
}

void lcd_clear(void)
{
	lcd_cmd(0x01);
}

void lcd_str(const char* str_)
{
	char i;
	for(i = 0; *(str_ + i) != '\0'; i++)
		lcd_data(*(str_ + i));
}