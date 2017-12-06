#ifndef REPL_H
#define REPL_H


#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "types.h"
#include "rpn.h"

/* ---- ---- ---- for REPL ---- ---- ---- */
void repl_set(REAL, REAL, SHIFT*);


#endif
