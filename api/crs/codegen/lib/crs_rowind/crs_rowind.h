#ifndef CRS_ROWIND_H
#define CRS_ROWIND_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "crs_rowind_types.h"

extern void crs_rowind(const emxArray_int32_T *rowptr, const emxArray_int32_T
  *js, emxArray_int32_T *is);
extern void crs_rowind_initialize(void);
extern void crs_rowind_terminate(void);
extern emxArray_int32_T *emxCreateND_int32_T(int numDimensions, int *size);
extern emxArray_int32_T *emxCreateWrapperND_int32_T(int *data, int numDimensions,
  int *size);
extern emxArray_int32_T *emxCreateWrapper_int32_T(int *data, int rows, int cols);
extern emxArray_int32_T *emxCreate_int32_T(int rows, int cols);
extern void emxDestroyArray_int32_T(emxArray_int32_T *emxArray);
extern void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);

#endif
