#ifndef CRS_ROWIND_H
#define CRS_ROWIND_H

#include "crs_rowind_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_rowind(const emxArray_int32_T *rowptr,
                       const emxArray_int32_T *js, emxArray_int32_T *is);

extern void crs_rowind_initialize(void);

extern void crs_rowind_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
