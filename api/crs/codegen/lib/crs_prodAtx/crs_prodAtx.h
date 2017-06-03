#ifndef CRS_PRODATX_H
#define CRS_PRODATX_H
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "crs_prodAtx_types.h"

extern void crs_prodAtx(const struct0_T *A, const emxArray_real_T *x,
  emxArray_real_T *b, const emxArray_int32_T *nthreads);
extern void crs_prodAtx_initialize(void);
extern void crs_prodAtx_ser(const struct0_T *A, const emxArray_real_T *x,
  emxArray_real_T *b);
extern void crs_prodAtx_ser1(const struct0_T *A, const emxArray_real_T *x,
  emxArray_real_T *b);
extern void crs_prodAtx_terminate(void);
extern emxArray_int32_T *emxCreateND_int32_T(int numDimensions, int *size);
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size);
extern emxArray_int32_T *emxCreateWrapperND_int32_T(int *data, int numDimensions,
  int *size);
extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
  numDimensions, int *size);
extern emxArray_int32_T *emxCreateWrapper_int32_T(int *data, int rows, int cols);
extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols);
extern emxArray_int32_T *emxCreate_int32_T(int rows, int cols);
extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
extern void emxDestroyArray_int32_T(emxArray_int32_T *emxArray);
extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void emxDestroy_struct0_T(struct0_T emxArray);
extern void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_struct0_T(struct0_T *pStruct);

#endif
