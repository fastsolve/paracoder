#ifndef CRS_SOLVE_UTRIU_H
#define CRS_SOLVE_UTRIU_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "crs_solve_utriu_types.h"

extern void crs_solve_utriu(const struct0_T *U, emxArray_real_T *b);
extern void crs_solve_utriu_3args(const struct0_T *L, emxArray_real_T *b, int
  offset);
extern void crs_solve_utriu_initialize(void);
extern void crs_solve_utriu_terminate(void);

#endif
