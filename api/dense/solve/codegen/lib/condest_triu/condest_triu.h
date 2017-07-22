#ifndef CONDEST_TRIU_H
#define CONDEST_TRIU_H
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "condest_triu_types.h"

extern void condest_triu(const emxArray_real_T *R, int m, int maxiter, double
  *kappa, struct0_T *buf);
extern void condest_triu_initialize(void);
extern void condest_triu_terminate(void);

#endif
