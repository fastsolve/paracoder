#ifndef CRS_SOLVE_UTRIL_H
#define CRS_SOLVE_UTRIL_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "crs_solve_utril_types.h"

extern void crs_solve_utril(const struct0_T *L, emxArray_real_T *b);
extern void crs_solve_utril_3args(const struct0_T *L, emxArray_real_T *b, int
  offset);
extern void crs_solve_utril_initialize(void);
extern void crs_solve_utril_terminate(void);

#endif
