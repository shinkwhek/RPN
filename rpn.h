#ifndef RPN_H
#define RPN_H

#include "types.h"
#include "rpn.h"

typedef enum {
  On = 0,
  Off
} SHIFT;


// 要請
typedef struct struct_stack {
  REAL real_part;
  struct struct_stack* next;
} STACK;

void new_stack(const REAL, STACK**);
void show_stack(STACK**, SHIFT*);
void plus_minus_rpn(SHIFT,STACK**);
void time_divided_rpn(SHIFT,STACK**);
void sqrt_pow_rpn(SHIFT,STACK**);
void sin_asin_stack(SHIFT, STACK**);
void cos_acos_stack(SHIFT, STACK**);
void tan_atan_stack(SHIFT, STACK**);
void log_log10_stack(SHIFT, STACK**);
void PI_E_stack(SHIFT, STACK**);
void init_stack(STACK**);

#endif
