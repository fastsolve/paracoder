#ifndef CRS_TRIU_H
#define CRS_TRIU_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "crs_triu_types.h"

extern void crs_triu(const struct0_T *A, struct0_T *U);
extern void crs_triu1(const struct0_T *A, int k, struct0_T *U);
extern void crs_triu_initialize(void);
extern void crs_triu_terminate(void);
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
extern void emxInit_struct0_T(struct0_T *pStruct);

#endif
