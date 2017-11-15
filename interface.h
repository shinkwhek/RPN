#ifndef INTERFACE_H
#define INTERFACE_H
#include"type.h"
#include"rpn.h"

typedef enum {
  NUMBER = 0,
  SETSHIFT,
  RESETSHIFT,
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

#endif
