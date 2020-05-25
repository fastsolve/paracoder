#ifndef CRS_SOLVE_UTRIUT_H
#define CRS_SOLVE_UTRIUT_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "crs_solve_utriut_types.h"

extern void crs_solve_utriut(const struct0_T *U, emxArray_real_T *b);
extern void crs_solve_utriut_3args(const struct0_T *U, emxArray_real_T *b, int
  offset);
extern void crs_solve_utriut_initialize(void);
extern void crs_solve_utriut_terminate(void);

#endif
