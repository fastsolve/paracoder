#ifndef CRS_PRODATAX_H
#define CRS_PRODATAX_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "crs_prodAtAx_types.h"

extern void crs_prodAtAx(const CRS_Matrix *A, const emxArray_real_T *x,
  emxArray_real_T *b, emxArray_real_T *Ax, const emxArray_int32_T *nthreads);
extern void crs_prodAtAx_initialize(void);
extern void crs_prodAtAx_ser(const CRS_Matrix *A, const emxArray_real_T *x,
  emxArray_real_T *b);
extern void crs_prodAtAx_ser1(const CRS_Matrix *A, const emxArray_real_T *x,
  emxArray_real_T *b);
extern void crs_prodAtAx_terminate(void);

#endif
