#ifndef LCD_H
#define LCD_H

#include <avr/io.h>
#include <util/delay.h>
#include "types.h"

#define LCD_RS 0b00000001
#define LCD_E  0b00000010
#define LCD_PORT PORTB


/* ---- ---- ---- for LCD ---- ---- ----*/
void lcd_init(void);
void lcd_out(const I8, const I8);
void lcd_cmd(const I8);
void lcd_data(const I8);
void lcd_pos(const I8, const I8);
void lcd_clear(void);
void lcd_str(const I8*);

#endif