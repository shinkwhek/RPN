/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "repl.h"
/*
#include "rpn.h"
#include "interface.h"
#include "types.h"
*/

/* ==== ==== ==== main loop ==== ==== ==== */
int main(void)
{
  PORTB = 0x00;
  DDRB  = 0xff;
  lcd_init();
/*
  STACK* root = &(STACK){ 0 };
  STACK* current_stack = root;
  SHIFT current_shift = Off;
  INTERFACE current_interface;
  init_stack(&current_stack);

#define do_order_macro(order_) do_order(order_,&current_shift, &current_interface, &current_stack)

  set_str("3.14159", &current_interface);
  do_order_macro(NUMBER);
  set_str("2.2",&current_interface);
  do_order_macro(NUMBER);
  do_order_macro(SHOW);
*/
  lcd_pos(1,1);
  lcd_str("hello");

  for(;;){

  }
  return 0;   /* never reached */
}

