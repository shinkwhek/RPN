#ifndef REPL_H
#define REPL_H


#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

#define REPL_Y_COL 0
#define REPL_X_COL 1

typedef double REAL;
typedef enum {
	X_COL = 0,
	Y_COL
} COL;

/* ---- ---- ---- for REPL ---- ---- ---- */
void repl_set(REAL, REAL);


#endif