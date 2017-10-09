/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

/* ---- ---- ---- for REPL ---- ---- ---- */
void repl_set(void);

/* ==== ==== ==== main loop ==== ==== ==== */
int main(void)
{
	PORTB = 0x00;
	DDRB  = 0xff;
	lcd_init();

	repl_set();
	
    for(;;){

    }
    return 0;   /* never reached */
}

/* ==== ==== ==== for REPL ==== ==== ==== */

void repl_set(void)
{
	lcd_pos(1,1); lcd_str("y:");
	lcd_pos(2,1); lcd_str("x:");
	lcd_pos(1,3);
}
