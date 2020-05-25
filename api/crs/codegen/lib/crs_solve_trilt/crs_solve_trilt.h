#ifndef CRS_SOLVE_TRILT_H
#define CRS_SOLVE_TRILT_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "crs_solve_trilt_types.h"

extern void crs_solve_trilt(const struct0_T *A, emxArray_real_T *b);
extern void crs_solve_trilt_initialize(void);
extern void crs_solve_trilt_terminate(void);

#endif
