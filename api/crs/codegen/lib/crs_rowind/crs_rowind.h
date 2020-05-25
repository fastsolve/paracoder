#ifndef CRS_ROWIND_H
#define CRS_ROWIND_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "crs_rowind_types.h"

extern void crs_rowind(const emxArray_int32_T *rowptr, const emxArray_int32_T
  *js, emxArray_int32_T *is);
extern void crs_rowind_initialize(void);
extern void crs_rowind_terminate(void);

#endif
