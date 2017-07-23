#ifndef BACKSOLVE_H
#define BACKSOLVE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "backsolve_types.h"

extern void backsolve(const emxArray_real_T *R, emxArray_real_T *bs, int cend,
                      const emxArray_real_T *ws);
extern void backsolve_2args(const emxArray_real_T *R, emxArray_real_T *bs);
extern void backsolve_3args(const emxArray_real_T *R, emxArray_real_T *bs, int
  cend);
extern void backsolve_initialize(void);
extern void backsolve_terminate(void);

#endif
