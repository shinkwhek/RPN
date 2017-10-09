/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "repl.h"

static inline void initial_setup(void);

/* ==== ==== ==== main loop ==== ==== ==== */
int main(void)
{
	PORTB = 0x00;
	DDRB  = 0xff;

	initial_setup();

    for(;;){

    }
    return 0;   /* never reached */
}

static inline void initial_setup(void)
{
	lcd_init();
	repl_set();
	repl_insert(REPL_Y_COL, "0.0000");
	repl_insert(REPL_X_COL, "0.0000");
}