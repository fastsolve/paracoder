#ifndef CONDEST_TRIU_H
#define CONDEST_TRIU_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "condest_triu_types.h"

extern double condest_triu(const emxArray_real_T *R, int m, int maxiter,
  CondestBuf *buf);
extern void condest_triu_3args(const emxArray_real_T *R, int m, int maxiter,
  double *kappa, CondestBuf *buf);
extern void condest_triu_initialize(void);
extern void condest_triu_terminate(void);

#endif
