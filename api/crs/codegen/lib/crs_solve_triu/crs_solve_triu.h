#ifndef CRS_SOLVE_TRIU_H
#define CRS_SOLVE_TRIU_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "crs_solve_triu_types.h"

extern void crs_solve_triu(const struct0_T *A, emxArray_real_T *b);
extern void crs_solve_triu_initialize(void);
extern void crs_solve_triu_terminate(void);

#endif
