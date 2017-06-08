#ifndef CRS_PRODAATX_H
#define CRS_PRODAATX_H
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "crs_prodAAtx_types.h"

extern void crs_prodAAtx(const struct0_T *A, const emxArray_real_T *x,
  emxArray_real_T *b, emxArray_real_T *Atx, const emxArray_int32_T *nthreads);
extern void crs_prodAAtx_initialize(void);
extern void crs_prodAAtx_ser(const struct0_T *A, const emxArray_real_T *x,
  emxArray_real_T *b);
extern void crs_prodAAtx_ser1(const struct0_T *A, const emxArray_real_T *x,
  emxArray_real_T *b);
extern void crs_prodAAtx_terminate(void);

#endif
