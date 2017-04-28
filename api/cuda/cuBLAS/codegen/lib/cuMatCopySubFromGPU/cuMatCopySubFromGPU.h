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

#endif
