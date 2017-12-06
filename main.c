
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "repl.h"

#include "rpn.h"
#include "interface.h"
#include "types.h"


void show_stack_count(void);


/* ==== ==== ==== main loop ==== ==== ==== */
int main(void)
{
  DDRB  = 0xff;
  DDRC  = 0b00000111;
  PORTB = 0x00;
  PORTC = 0x00;
  lcd_init();

  // ---------
  stack_count = 0;
  btm_count = 0;
  btm_mode = 0;
  STACK* root = malloc(sizeof(STACK));
  STACK* current_stack = root;
  SHIFT current_shift = Off;
  INTERFACE current_interface;
  init_stack(&current_stack);

  do_order(SHOW, &current_shift, &current_interface, &current_stack);
  show_stack_count ();

#define do_order_macro(orda) do_order(orda,&current_shift,&current_interface,&current_stack)

  for(;;){
    if( bit_is_clear(PIND, PIND7) ) {
      _delay_ms(5);
      btm_count ++;
      while(bit_is_clear(PIND, PIND7));
      _delay_ms(5);
    }
    if( bit_is_clear(PIND, PIND6) ) {
      char buf[2];
      sprintf(buf, "%d", btm_count % 10);
      set_str(buf, &current_interface);
      btm_count = 0;
      do_order_macro(NUMBER);
      do_order_macro(SHOW);
      show_stack_count();
    }
    if ( bit_is_clear(PIND, PIND5) ) {
      ORDER tmp = (ORDER)((btm_count % 8) + 1);
      btm_count = 0;
      do_order_macro(tmp);
      do_order_macro(SHOW);
      show_stack_count();
    }

  }
  return 0;   /* never reached */
}

void show_stack_count (void) {
  PORTC = (PORTC & 0b11111000) | (stack_count & 0b00000111);
}

