#ifndef CRS_SORT_H
#define CRS_SORT_H

#include "crs_sort_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_sort(const emxArray_int32_T *row_ptr, emxArray_int32_T *col_ind,
                     emxArray_real_T *val);

extern void crs_sort0(const emxArray_int32_T *row_ptr,
                      emxArray_int32_T *col_ind);

extern void crs_sort_initialize(void);

extern void crs_sort_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
