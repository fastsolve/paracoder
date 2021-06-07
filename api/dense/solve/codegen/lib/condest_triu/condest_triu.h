#ifndef CONDEST_TRIU_H
#define CONDEST_TRIU_H

#include "condest_triu_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern double condest_triu(const emxArray_real_T *R, int m, int maxiter,
                           CondestBuf *buf);

extern void condest_triu_3args(const emxArray_real_T *R, int m, int maxiter,
                               double *kappa, CondestBuf *buf);

extern void condest_triu_initialize(void);

extern void condest_triu_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
