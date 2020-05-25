#ifndef CRS_CREATEFROMAIJ_H
#define CRS_CREATEFROMAIJ_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "crs_createFromAIJ_types.h"

extern void crs_create1(const emxArray_int32_T *is, const emxArray_int32_T *js,
  const emxArray_real_T *vs, int ni, int nj, struct0_T *A);
extern void crs_createFromAIJ(const emxArray_int32_T *rows, const
  emxArray_int32_T *cols, const emxArray_real_T *vs, struct0_T *A);
extern void crs_createFromAIJ_initialize(void);
extern void crs_createFromAIJ_terminate(void);

#endif
