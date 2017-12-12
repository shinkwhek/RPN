#ifndef INTERFACE_H
#define INTERFACE_H
#include"types.h"
#include"rpn.h"

typedef enum {
  NUMBER = 0,
  ADC_ENUM,
  SETSHIFT,
  PLUS_MINUS,
  TIME_DIVIDED,
  SIN_ASIN,
  COS_ACOS,
  TAN_ATAN,
  SQRT_POW,
  LOG_LOG10,
  PI_E,
  SHOW
} ORDER;

typedef struct {
  I8 str[15];
} INTERFACE;

void do_order (ORDER, SHIFT*, INTERFACE*, STACK**);
void set_str (const I8*, INTERFACE*);


int btm_count;
int btm_mode; // 1:num, 2:func, 3:shift_func

#endif
