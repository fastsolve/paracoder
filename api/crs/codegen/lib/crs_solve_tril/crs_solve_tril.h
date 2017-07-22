#ifndef CRS_SOLVE_TRIL_H
#define CRS_SOLVE_TRIL_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "crs_solve_tril_types.h"

extern void crs_solve_tril(const struct0_T *A, emxArray_real_T *b);
extern void crs_solve_tril_initialize(void);
extern void crs_solve_tril_terminate(void);

#endif
