/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "repl.h"
#include "types.h"

static inline void initial_setup(void);

/* ==== ==== ==== main loop ==== ==== ==== */
I32 main(void)
{
	PORTB = 0x00;
	DDRB  = 0xff;

	initial_setup();

	_delay_ms(100);
	repl_set(3.14159265, 1234.456789);

    for(;;){

    }
    return 0;   /* never reached */
}

static inline void initial_setup(void)
{
	lcd_init();
	repl_set(0, 0);
}