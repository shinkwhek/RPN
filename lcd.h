#ifndef LCD_H
#define LCD_H

#include <avr/io.h>
#include <util/delay.h>

#define LCD_RS 0b00000001
#define LCD_E  0b00000010
#define LCD_PORT PORTB

/* ---- ---- ---- for LCD ---- ---- ----*/
void lcd_init(void);
void lcd_out(const char ,const char);
void lcd_cmd(const char);
void lcd_data(const char);
void lcd_pos(const char, const char);
void lcd_clear(void);
void lcd_str(const char*);

#endif