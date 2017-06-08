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

#endif
