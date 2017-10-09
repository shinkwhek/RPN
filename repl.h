#ifndef REPL_H
#define REPL_H


#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

#define REPL_Y_COL 0
#define REPL_X_COL 1

/* ---- ---- ---- for REPL ---- ---- ---- */
void repl_insert(int, float);
void repl_set(void);


#endif