#ifndef CRS_SOLVE_UTRILT_H
#define CRS_SOLVE_UTRILT_H

#include "crs_solve_utrilt_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_solve_utrilt(const CRS_Matrix *L, emxArray_real_T *b);

extern void crs_solve_utrilt_3args(const CRS_Matrix *L, emxArray_real_T *b,
                                   int offset);

extern void crs_solve_utrilt_initialize(void);

extern void crs_solve_utrilt_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
