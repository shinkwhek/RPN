/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "repl.h"

#include "rpn.h"
#include "interface.h"
#include "types.h"


/* ==== ==== ==== main loop ==== ==== ==== */
int main(void)
{
  PORTB = 0x00;
  DDRB  = 0xff;
  lcd_init();

  STACK* root = malloc(sizeof(STACK));
  STACK* current_stack = root;
  SHIFT current_shift = Off;
  INTERFACE current_interface;
  init_stack(&current_stack);

#define do_order_macro(order_) do_order(order_,&current_shift, &current_interface, &current_stack)

  do_order_macro(PI_E);
  do_order_macro(PI_E);
  do_order_macro(COS_ACOS);
  do_order_macro(SHOW);


  for(;;){

  }
  return 0;   /* never reached */
}

