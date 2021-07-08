#ifndef CRS_UNIQUE_H
#define CRS_UNIQUE_H

#include "crs_unique_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_unique(emxArray_int32_T *row_ptr, emxArray_int32_T *col_ind,
                       emxArray_real_T *val);

extern void crs_unique_initialize(void);

extern void crs_unique_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
