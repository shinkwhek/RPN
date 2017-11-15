#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "type.h"
#include "rpn.h"
#include "repl.h"

void
new_stack (const REAL data_, STACK** stacks_) {
  STACK* new = malloc(sizeof(STACK));
  new->real_part = data_;
  new->next = *stacks_;
  *stacks_ = new;
}

void
show_stack (STACK** stacks_) {
  STACK* Y = (*stacks_)->next;
  STACK* X = (*stacks_);
  repl_set(Y->real_part, X->real_part);
}

static inline void
plus_stack (STACK** stacks_) {
  /* (Y X +) */
  STACK* Y = (*stacks_)->next;
  STACK* X = (*stacks_);
  Y->real_part = Y->real_part + X->real_part;
  *stacks_ = Y;
  free(X);
}

static inline void
minus_stack (STACK** stacks_) {
  /* (Y X -) */
  STACK* Y = (*stacks_)->next;
  STACK* X = (*stacks_);
  Y->real_part = Y->real_part- X->real_part;
  *stacks_ = Y;
  free(X);
}

static inline void
time_stack(STACK** stacks_) {
  /* (Y X *) */
  STACK* Y = (*stacks_)->next;
  STACK* X = (*stacks_);
  Y->real_part = Y->real_part * X->real_part;
  *stacks_ = Y;
  free(X);
}

static inline void
divided_stack (STACK** stacks_) {
  /* (Y X /) */
  STACK* Y = (*stacks_)->next;
  STACK* X = (*stacks_);
  Y->real_part = Y->real_part / X->real_part;
  *stacks_ = Y;
  free(X);
}

static inline void
sqrt_stack (STACK** stacks_) {
  /* sqrt(x) */
  STACK* X = (*stacks_);
  X->real_part = sqrt(X->real_part);
}

static inline void
pow_stack (STACK** stacks_) {
  /* y^x */
  STACK* Y = (*stacks_)->next;
  STACK* X = (*stacks_);
  Y->real_part = pow(Y->real_part, X->real_part);
  *stacks_ = Y;
  free(X);
}

void
sin_asin_stack (SHIFT shift_,STACK** stacks_) {
  STACK* X = (*stacks_);
  if (shift_ == Off)
    X->real_part = sin(X->real_part);
  else
    X->real_part = asin(X->real_part);
}

void
cos_acos_stack (SHIFT shift_, STACK** stacks_) {
  STACK* X = (*stacks_);
  if (shift_ == Off)
    X->real_part = cos(X->real_part);
  else
    X->real_part = acos(X->real_part);
}

void
tan_atan_stack (SHIFT shift_, STACK** stacks_) {
  STACK* X = (*stacks_);
  if (shift_ == Off)
    X->real_part = tan(X->real_part);
  else
    X->real_part = atan(X->real_part);
}

void
log_log10_stack (SHIFT shift_, STACK** stacks_) {
  STACK* X = (*stacks_);
  if (shift_ == Off)
    X->real_part = log(X->real_part);
  else
    X->real_part = log10(X->real_part);
}

void
plus_minus_rpn (SHIFT shift_, STACK** stacks_) {
  if (shift_ == Off)
    plus_stack(stacks_);
  else
    minus_stack(stacks_);
}

void
time_divided_rpn (SHIFT shift_, STACK** stacks_) {
  if (shift_ == Off)
    time_stack(stacks_);
  else
    divided_stack(stacks_);
}

void
sqrt_pow_rpn (SHIFT shift_, STACK** stacks_) {
  if (shift_ == Off)
    sqrt_stack(stacks_);
  else
    pow_stack(stacks_);
}

void
PI_E_stack (SHIFT shift_, STACK** stacks_) {
  if (shift_ == Off)
    new_stack(M_PI, stacks_);
  else
    new_stack(M_E, stacks_);
}

void
init_stack (STACK** stacks_) {
  new_stack(0, stacks_);
  new_stack(0, stacks_);
}

