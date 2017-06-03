#ifndef CRS_CREATE_H
#define CRS_CREATE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "crs_create_types.h"

extern void crs_create(const emxArray_int32_T *rows, const emxArray_int32_T
  *cols, const emxArray_real_T *vs, struct0_T *A);
extern void crs_create0(int ni, int nj, struct1_T *A);
extern void crs_create1(const emxArray_int32_T *is, const emxArray_int32_T *js,
  const emxArray_real_T *vs, int ni, int nj, struct0_T *A);
extern void crs_create_initialize(void);
extern void crs_create_terminate(void);
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
extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInit_struct0_T(struct0_T *pStruct);

#endif
