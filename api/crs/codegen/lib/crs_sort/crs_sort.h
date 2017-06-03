#ifndef CRS_SORT_H
#define CRS_SORT_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "crs_sort_types.h"

extern void crs_sort(const emxArray_int32_T *row_ptr, emxArray_int32_T *col_ind,
                     emxArray_real_T *val);
extern void crs_sort0(const emxArray_int32_T *row_ptr, emxArray_int32_T *col_ind);
extern void crs_sort_initialize(void);
extern void crs_sort_terminate(void);
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
extern void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);

#endif
