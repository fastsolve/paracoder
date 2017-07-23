#ifndef SOLVE_GETRS_H
#define SOLVE_GETRS_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "solve_getrs_types.h"

extern void solve_getrs(const emxArray_real_T *A, emxArray_real_T *b);
extern void solve_getrs_3args(const emxArray_real_T *A, emxArray_real_T *b, int
  n);
extern void solve_getrs_initialize(void);
extern void solve_getrs_terminate(void);

#endif
