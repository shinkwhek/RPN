#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "repl.h"
#include <stdio.h>

/* ==== ==== ==== for REPL ==== ==== ==== */

void repl_insert(int col_ , float real_)
{
	char s[15];

	if (col_ == REPL_Y_COL) {
		lcd_pos(1,1);
		sprintf(s, "Y: %.4f", real_);
		lcd_str(s);
	}
	else if (col_ == REPL_X_COL) {
		lcd_pos(2,1);
		sprintf(s, "X: %.4f", real_);
		lcd_str(s);
	}
}


void repl_set(void)
{
	repl_insert(REPL_Y_COL, 0);
	repl_insert(REPL_X_COL, 0);
}
