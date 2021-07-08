#ifndef CRS_UNIQUECOLIND_H
#define CRS_UNIQUECOLIND_H

#include "crs_uniqueColInd_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_uniqueColInd(emxArray_int32_T *row_ptr,
                             emxArray_int32_T *col_ind, emxArray_real_T *val);

extern void crs_uniqueColInd_initialize(void);

extern void crs_uniqueColInd_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
