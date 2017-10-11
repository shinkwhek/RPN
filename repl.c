#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "repl.h"
#include "types.h"
#include <stdio.h>

/* ==== ==== ==== for REPL ==== ==== ==== */

static inline void print_real(REAL real_)
{
	I8 s[14];
	U64 hd, tl;

	if(real_ >= 0){
		hd = (U64)real_;
		tl = (U64)((real_-hd)*10000);
		sprintf(s," %ld.%-ld",hd,tl);
	}
	lcd_str(s);
}

static void repl_insert(COL col_ , REAL real_)
{
	if (col_ == Y_COL) {
		lcd_pos(1,1);
		lcd_str("Y:");
	} else
	if (col_ == X_COL) {
		lcd_pos(2,1);
		lcd_str("X:");
	}
	print_real(real_);
}

void repl_set(REAL real_y_, REAL real_x_)
{
	lcd_clear();
	repl_insert(Y_COL, real_y_);
	repl_insert(X_COL, real_x_);
}
