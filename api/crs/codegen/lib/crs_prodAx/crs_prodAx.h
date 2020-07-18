#ifndef CRS_PRODAX_H
#define CRS_PRODAX_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "crs_prodAx_types.h"

extern void crs_prodAx(const CRS_Matrix *A, const emxArray_real_T *x,
  emxArray_real_T *b, int nthreads);
extern void crs_prodAx_initialize(void);
extern void crs_prodAx_ser(const CRS_Matrix *A, const emxArray_real_T *x,
  emxArray_real_T *b);
extern void crs_prodAx_ser1(const CRS_Matrix *A, const emxArray_real_T *x,
  emxArray_real_T *b);
extern void crs_prodAx_terminate(void);

#endif
