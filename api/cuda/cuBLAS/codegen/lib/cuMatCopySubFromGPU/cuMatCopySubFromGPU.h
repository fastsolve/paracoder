#ifndef CUMATCOPYSUBFROMGPU_H
#define CUMATCOPYSUBFROMGPU_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuMatCopySubFromGPU_types.h"

extern void cuMatCopySubFromGPU(int nrows, int ncols, const struct0_T *cuMat,
  const emxArray_real_T *mat, int *errCode, boolean_T *toplevel);
extern void cuMatCopySubFromGPU_async(int nrows, int ncols, const struct0_T
  *cuMat, const emxArray_real_T *mat, const struct1_T *strm, int *errCode,
  boolean_T *toplevel);
extern void cuMatCopySubFromGPU_initialize(void);
extern void cuMatCopySubFromGPU_terminate(void);
extern emxArray_char_T *emxCreateND_char_T(int numDimensions, int *size);
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size);
extern emxArray_uint8_T *emxCreateND_uint8_T(int numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapperND_char_T(char *data, int numDimensions,
  int *size);
extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
  numDimensions, int *size);
extern emxArray_uint8_T *emxCreateWrapperND_uint8_T(unsigned char *data, int
  numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapper_char_T(char *data, int rows, int cols);
extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols);
extern emxArray_uint8_T *emxCreateWrapper_uint8_T(unsigned char *data, int rows,
  int cols);
extern emxArray_char_T *emxCreate_char_T(int rows, int cols);
extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
extern emxArray_uint8_T *emxCreate_uint8_T(int rows, int cols);
extern void emxDestroyArray_char_T(emxArray_char_T *emxArray);
extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void emxDestroyArray_uint8_T(emxArray_uint8_T *emxArray);
extern void emxDestroy_struct1_T(struct1_T emxArray);
extern void emxInit_struct1_T(struct1_T *pStruct);

#endif
