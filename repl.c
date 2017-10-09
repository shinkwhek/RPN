#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "repl.h"

/* ==== ==== ==== for REPL ==== ==== ==== */

void repl_set(void)
{
	lcd_pos(1,1); lcd_str("y:");
	lcd_pos(2,1); lcd_str("x:");
}

void repl_insert(const int col_ ,const char* str_)
{
	if (col_ == REPL_Y_COL)      lcd_pos(1,4);
	else if (col_ == REPL_X_COL) lcd_pos(2,4);
	lcd_str(str_);
}