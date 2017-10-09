#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "repl.h"

/* ==== ==== ==== for REPL ==== ==== ==== */

void repl_set(void)
{
	lcd_pos(1,1); lcd_str("y:");
	lcd_pos(2,1); lcd_str("x:");
	lcd_pos(1,3);
}