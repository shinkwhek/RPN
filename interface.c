#include"interface.h"
#include"types.h"
#include"rpn.h"
#include"adc.h"
#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include <util/delay.h>

void
set_str (const I8* str, INTERFACE* interface_) {
  strcpy(interface_->str, str);
}

void
do_order (ORDER order_, SHIFT* shift_, INTERFACE* interface_, STACK** stacks_) {
  switch(order_) {
    case NUMBER:
      {
        const REAL r = atof(interface_->str);
        new_stack(r, stacks_);
        break;
      }
    case ADC_ENUM:
      {
        // ADCスタート
        ADCSRA |= _BV(ADIF);
        ADCSRA |= _BV(ADSC);
        // ADC完了待ち
        loop_until_bit_is_set(ADCSRA, ADIF);
        // ADC結果取得
        const REAL r = ADC;
        new_stack(r, stacks_);
        break;
      }
    case SETSHIFT:
      if (*shift_ == Off) *shift_ = On;
      else                *shift_ = Off;
      break;
    case PLUS_MINUS:
      plus_minus_rpn(*shift_, stacks_);
      break;
    case TIME_DIVIDED:
      time_divided_rpn(*shift_, stacks_);
      break;
    case SIN_ASIN:
      sin_asin_stack(*shift_, stacks_);
      break;
    case COS_ACOS:
      cos_acos_stack(*shift_, stacks_);
      break;
    case TAN_ATAN:
      tan_atan_stack(*shift_, stacks_);
      break;
    case SQRT_POW:
      sqrt_pow_rpn(*shift_, stacks_);
      break;
    case LOG_LOG10:
      log_log10_stack(*shift_, stacks_);
      break;
    case PI_E:
      PI_E_stack(*shift_, stacks_);
      break;
    case SHOW:
      show_stack(stacks_, shift_);
      break;
    default: break;
  }
}

